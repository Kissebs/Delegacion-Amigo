#include <iostream>

using namespace std;

class Persona {
private:
	string nombre;

public:

	Persona(string nom) : nombre(nom) {
		cout << "Creando persona base" << endl;
	
	}
	virtual ~Persona() {
	
	}

	void alimenta() {
		cout << "yo" << nombre << "me alimento" << endl;
	}

	void camina() {
		cout << "yo" << nombre << "camino" << endl;
	}
	void duerme() {
		cout << "yo" << nombre << "duermo" << endl;

	}

};

class Estudiante {
public:

	void asistirALecciones() {
	
	}

};

class Deportista {

public:

	Deportista() {
	
	}

	virtual ~Deportista() {}
	void carreraMaraton() {
		cout << "Corro maraton por las carreteras" << endl;
	}

	void saltoAlto() {

		cout << "Soy deportista y salto como el sapito" << endl;
	}


};

class Amigo : public Persona{
private:
	Estudiante* estudiante;//aqui se meten los chips de deportista y estudiante en la class amigo
	Deportista* deportista;
public:
	Amigo(string nom) :Persona(nom){
		cout << "Creando objeto amigo" << endl;

		estudiante = new Estudiante;
		deportista = new Deportista;
	
	}

	virtual ~Amigo() {
		cout << "Eliminando Amigo" << endl;
		delete estudiante;
		delete deportista;

	}
	void asistirALecciones() { //Aqui se establece lo unico que quiere hacer como estudiante
		estudiante->asistirALecciones();

	}
	void saltoAlto() { //Aqui se establece lo unico que quiere hacer como deportista
		deportista->saltoAlto();
	}

	void cosasPropiasDeAmigo() {
		cout << "Cosas propias de la clase amigo" << endl;
	}
};

int main() {
	//creando la instancia de la clase amigo (Esta es la cara, el resto permanece escondido);
	//probar un main donde se realiza con datos quemados
	

	Amigo* amigo = new Amigo("Pablo");

	amigo->cosasPropiasDeAmigo();
	amigo->alimenta();
	amigo->camina();
	

	system("pause");
	return 0;


}