import 'package:flutter/material.dart';
import 'package:fonda/pages/main_fonda_page.dart';
import 'package:google_fonts/google_fonts.dart';
import 'package:fonda/components/fonda_button.dart';
import 'package:fonda/theme/theme.dart';

class IntroFondaPage extends StatelessWidget {
  const IntroFondaPage({super.key});

  @override
  Widget build(BuildContext context) {
    return Scaffold(
        backgroundColor: Color(0xffcde0ef),
        body: Padding(
          padding: EdgeInsets.symmetric(horizontal: 20),
          child: Column(
            mainAxisAlignment: MainAxisAlignment.spaceEvenly,
            children: [
              //row con la bandera y el texto
              Row(
                children: [
                  Image.asset(
                    'images/chile.png',
                    height: 40,
                    width: 40,
                  ),
                  SizedBox(
                    width: 20,
                  ),
                  Text('Fonda App',
                      style: GoogleFonts.lilitaOne(
                        color: azulPrimario,
                        fontSize: 20,
                      )),
                ],
              ),

              //row con las2 fotos
              Row(
                children: [
                  Expanded(child: Image.asset('images/huaso.png')),
                  Expanded(child: Image.asset('images/huasa.png')),
                ],
              ),
              //titulo

              Text(
                'EL SABOR DE LA COMIDA CHILENA',
                style: GoogleFonts.lilitaOne(
                  color: azulPrimario,
                  fontSize: 30,
                ),
              ),
              //descripcion
              Text(
                'En estas fiestas patrias puedes degustar de nuestra gastronimia en la fonda',
                style: TextStyle(color: azulPrimario),
              ),
              GestureDetector(
                onTap: () {
                  Navigator.push(
                      context,
                      MaterialPageRoute(
                          builder: (context) => const MainFondaPages()));
                },
                child: FondaButton(),
              )
              //boton
            ],
          ),
        ));
  }
}
