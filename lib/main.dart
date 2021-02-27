import 'package:flutter/material.dart';

void main() {
  runApp(MyApp());
}

class MyApp extends StatefulWidget {
  @override
  _MyAppState createState() => _MyAppState();
}

class _MyAppState extends State<MyApp> {
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
          backgroundColor: Colors.blue[400],
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
                      Text('No ALerts',
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
                      Text('LPG Cylinder level: 30%',
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


          ],
        ),
      ),
    );
  }
}
