import 'package:flutter/material.dart';
import 'package:audioplayers/audio_cache.dart';

void main() {
  runApp(MyApp());
}

class MyApp extends StatefulWidget {
  @override
  _MyAppState createState() => _MyAppState();
}

class _MyAppState extends State<MyApp> {
  int a = 1; // 1 means leak, 2 means no leak.
  String c = "30%";
  String d = "No Alerts";
  @override
  Widget build(BuildContext context) {
    return MaterialApp(
      home: Scaffold(
        appBar: AppBar(
          title: Center(
            child: Text('SPARKLPG',
                style: TextStyle(
                  fontFamily: 'RobotoMono',
                  fontSize: 55,
                  fontWeight: FontWeight.bold,
                  color: Colors.white,
                )),
          ),
          backgroundColor: Colors.red[400],
        ),
        body: Stack(
          children: [
            Column(
              children: [
                Card(
                  child: Row(
                    children: [
                      Text('Alerts:',
                          style: TextStyle(
                            fontSize: 40,
                            fontWeight: FontWeight.bold,
                            color: Colors.red,
                          )),
                      SizedBox(width: 10),
                      Text('$d',
                          style: TextStyle(
                            fontSize: 20,
                            color: Colors.green,
                          )),
                    ],
                  ),
                ),
                SizedBox(height: 20),
                Card(
                  child: Row(
                    children: [
                      Text('LPG Cylinder level: $c',
                          style: TextStyle(
                            fontSize: 20,
                            fontWeight: FontWeight.bold,
                            color: Colors.red,
                          )),
                    ],
                  ),
                ),
              ],
            ),
            Center(
              child: FlatButton(
                onPressed: () {
                  setState(() {
                    final player = AudioCache();
                    if (a == 1) {
                      player.play('TF026.WAV');
                      d = "Leakage detected!";
                    }
                  });
                },
                child: Text('Refresh',
                    style: TextStyle(
                      fontSize: 20,
                      fontWeight: FontWeight.bold,
                      color: Colors.blue[400],
                    )),
              ),
            ),
            Positioned(
              top: 500,
              child: FlatButton(
                onPressed: () {
                  setState(() {
                    d = "No Alerts";
                  });
                },
                child: Text('Reset',
                    style: TextStyle(
                      fontSize: 20,
                      fontWeight: FontWeight.bold,
                      color: Colors.blue[400],
                    )),
              ),
            ),
          ],
        ),
      ),
    );
  }
}
