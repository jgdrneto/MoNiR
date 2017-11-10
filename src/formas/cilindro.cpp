double Cilindro::obterVolumeTotal(){

	return M_PI * this->raio * this->raio * this->dimensoes[0];

}

double Cilindro::obterVolumeAtual(double altura){

	return M_PI * this->raio * this->raio * altura;

}