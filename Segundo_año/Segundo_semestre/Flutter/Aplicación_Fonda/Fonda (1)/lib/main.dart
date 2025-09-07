import 'package:flutter/material.dart';
import 'package:fonda/pages/intro_fonda_page.dart';

void main() {
  // runApp(MyApp());
  runApp(MaterialApp(
    home: IntroFondaPage(),
  ));
}

class MyApp extends StatelessWidget {
  const MyApp({super.key});
  @override
  Widget build(BuildContext context) {
    return MaterialApp(
      debugShowCheckedModeBanner: false,
      home: Scaffold(
        body: Stack(
          //Fondo azul
          children: [
            Container(
              width: double.infinity,
              height: double.infinity,
              color: Color(0xff6bc5ff),
            ),
            Positioned(
              top: 40,
              left: 0,
              right: 0,
              child: Text(
                "Fonda App",
                textAlign: TextAlign.center,
                style: TextStyle(
                  color: Color(0xff125389),
                  fontSize: 30,
                  fontWeight: FontWeight.bold,
                ),
              ),
            ),
            Positioned(
              top: 330,
              left: 0,
              right: 90,
              child: Text("EL SABOR DE LA COMIDA CHILEA",
                  textAlign: TextAlign.center,
                  style: TextStyle(
                      color: Color(0xff2037ba),
                      fontSize: 30,
                      fontWeight: FontWeight.bold)),
            ),
            Align(
                //Boton (no es boton de hecho xd)
                alignment: Alignment(0, 0.8),
                child: Container(
                  height: 60,
                  width: 310,
                  decoration: BoxDecoration(
                    borderRadius: BorderRadius.circular(20),
                    color: Color(0xff1c4aae),
                  ),
                  //Texto dentro del boton
                  child: Center(
                      child: Text(
                    "Comenzar",
                    style: TextStyle(
                      color: Colors.white,
                      fontSize: 24,
                      fontWeight: FontWeight.bold,
                    ),
                  )),
                ))
          ],
        ),
      ),
    );
  }
}
