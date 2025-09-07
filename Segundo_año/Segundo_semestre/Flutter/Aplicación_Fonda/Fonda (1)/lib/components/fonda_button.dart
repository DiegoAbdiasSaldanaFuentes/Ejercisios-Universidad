import 'package:flutter/material.dart';
import 'package:fonda/theme/theme.dart';

class FondaButton extends StatelessWidget {
  const FondaButton({super.key});

  @override
  Widget build(BuildContext context) {
    return Container(
      padding: EdgeInsets.symmetric(
        vertical: 20,
      ),
      decoration: BoxDecoration(
        color: azulPrimario,
        borderRadius: BorderRadius.circular(20),
      ),
      child: Row(
        mainAxisAlignment: MainAxisAlignment.center,
        children: [
          Icon(
            Icons.play_arrow,
            color: Colors.white,
          ),
          Text(
            'Comenzar',
            style: TextStyle(color: Colors.white),
          )
        ],
      ),
    );
  }
}
