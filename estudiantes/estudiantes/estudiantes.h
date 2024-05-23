#pragma once
#include <mysql.h>
#include <iostream>
#include <string>
#include "ConexionBD.h"
#include "estudiantes.h"
#include "ConexionDB.h"
using namespace std;

class estudiantes:estudiantes{

public: string codigo,nombres,apellidos,direccion, fecha_nacimiento;
	  int telefono = 0,id_tipo_sangre=0;
	 
		
	public:
		estudiantes() {
		}
		estudiantes(string cod, string nom, string ape, string dir,string fn, int tel, int tipo) {
		codigo = cod;
		nombres = nom;
		apellidos = ape;
		direccion = dir;
		telefono = tel;
		id_tipo_sangre = tipo;
		fecha_nacimiento = fn;

	}

// Getters
string getCodigo() { return codigo; }
string getNombres() { return nombres; }
string getApellidos(){ return apellidos; }
string getDireccion() { return direccion; }
int getTelefono(){ return telefono; }
int getIdTipoSangre(){ return id_tipo_sangre; }
string fecha_nacimiento() {return fecha_nacimiento; }

// Setters
void setCodigo(const string& codigo) { this->codigo = codigo; }
void setNombres(const string& nombres) { this->nombres = nombres; }
void setApellidos(const string& apellidos) { this->apellidos = apellidos; }
void setDireccion(const string& direccion) { this->direccion = direccion; }
void setTelefono(int telefono) { this->telefono = telefono; }
void setIdTipoSangre(int id_tipo_sangre) { this->id_tipo_sangre = id_tipo_sangre; }
void setfecha_nacimiento(const string& fecha_nacimiento) { this->fecha_nacimiento= fecha_nacimiento;}

	void borrar() {
		int q_estado;
		ConexionBD cn = ConexionBD();

		cn.abrir_conexion();
		string ii = (codigo);
		if (cn.getConectar()) {
			string  borrar =
				"delete from estudiantes where codigo = " + ii + "";
			const char* i = borrar.c_str();
			q_estado = mysql_query(cn.getConectar(), i);
			if (!q_estado) {
				cout << "se ha eliminado " << endl;
			}
			else {
				cout << " ---- Error ingreso----" << endl;
			}
		}
		else {
			cout << " ---- Error conexion ----" << endl;
		}
		cn.cerrar_conexion();
	}
	void actualizar() {
		int q_estado;
		ConexionBD cn = ConexionBD();

		cn.abrir_conexion();
		if (cn.getConectar()) {
			string  actualizar =
				"update estudiantes set nombres='" + nombres + "', apellidos = '" + apellidos + "', direccion = '" + direccion + "', telefono ='" + to_string(telefono) + "', fecha_nacimiento='" + fecha_nacimiento +"',id_tipo_sangre='"+ to_string(id_tipo_sangre) + "', where codigo = " + codigo + "";
			const char* i = actualizar.c_str();
			q_estado = mysql_query(cn.getConectar(), i);
			if (!q_estado) {
				cout << "Actualizacion con exito..." << endl;
			}
			else {
				cout << "---- Error al Ingreso ---" << endl;
			}
		}
		else {
			cout << " ---- Conexion con error ----" << endl;
		}
		cn.cerrar_conexion();
	}
	void crear() {
		int q_estado;
		ConexionBD cn = ConexionBD();

		cn.abrir_conexion();
	       	if (cn.getConectar()) {
  			string  insertar =
				"INSERT INTO estudiantes(codigo,nombres,apellidos,direccion,telefono,fecha_nacimiento,id_tipo_sangre) VALUES ('" + codigo + "','" + nombres + "','" + apellidos + "','" + direccion + "'," + to_string(telefono) + ",'" + fecha_nacimiento + "','" + to_string(id_tipo_sangre) + "')";
			const char* i = insertar.c_str();
			q_estado = mysql_query(cn.getConectar(), i);
			if (!q_estado) {
				cout << "Ingreso con exito" << endl;
			}
			else {
				cout << "--- Error al Ingresar ----- " << endl;
			}
		}
		else {
			cout << "----  Error con la Conexion-- " << endl;
		}
		cn.cerrar_conexion();
	}
	void leer() {
		int q_estado;
		ConexionBD cn = ConexionBD();
		MYSQL_ROW fila;
		MYSQL_RES* resultado;
		cn.abrir_conexion();

		if (cn.getConectar()) {

			cout << "/// Datos de estudiantes ///" << endl;
			string consulta = "select * from estudiantes";
			const char* c = consulta.c_str();
			q_estado = mysql_query(cn.getConectar(), c);
			if (!q_estado) {
				resultado = mysql_store_result(cn.getConectar());
				while (fila = mysql_fetch_row(resultado)) {
					cout << fila[0] << "," << fila[1] << "," << fila[2] << "," << fila[3] << "," << fila[4] << "," << fila[5] << "," << fila[6] << "," << fila[7] << endl;
				}

			}
			else {
				cout << "---Error en la consulta----" << endl;
			}

		}
		else {
			cout << " xxx Error en la Conexion--------" << endl;
		}
		cn.cerrar_conexion();
	}
};