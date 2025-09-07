import 'package:flutter/material.dart';
import 'package:google_fonts/google_fonts.dart';

class CardPromo extends StatelessWidget {
  const CardPromo({super.key});

  @override
  Widget build(BuildContext context) {
    return Container(
        padding: EdgeInsets.all(20),
        decoration: BoxDecoration(
            color: Colors.red[700], borderRadius: BorderRadius.circular(20)),
        child: Row(
          children: [
            Expanded(
              child: Column(children: [
                Text(
                  'Promo 10%',
                  style: GoogleFonts.lilitaOne(
                    fontSize: 25,
                    color: Colors.white,
                  ),
                ),
                Container(
                  child: Text('Obtener'),
                )
              ]),
            ),
            Expanded(
              child: Image.asset('images/pollo.png'),
            )
          ],
        ));
  }
}
