import 'package:flutter/material.dart';

import 'screens/main_screen.dart';

void main() {
  runApp(MyApp());
}

//base class
class MyApp extends StatelessWidget {
  @override
  Widget build(BuildContext context) {
    return MaterialApp(
      debugShowCheckedModeBanner: false,
      home: MainScreen(),
      theme: ThemeData.dark(),
    );
  }
}
