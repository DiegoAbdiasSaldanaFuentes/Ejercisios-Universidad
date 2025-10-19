import 'package:ejemplosapi/model/user.dart';
import 'package:http/http.dart' as http;
import 'dart:convert';

class Api {

  Future<List<User>> fetchUsers ()async{
    final response = await http.get(Uri.parse('https://randomuser.me/api/?results=20'));

    if(response.statusCode==200){
      dynamic jsonData = json.decode(response.body);
      List<dynamic> listData = jsonData['results'];
      return listData.map((json) => User.fromJSON(json)).toList();
    }else{
      throw Exception('Error de conexion');
    }

  }

}
