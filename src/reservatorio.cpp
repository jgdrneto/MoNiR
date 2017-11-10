Reservatorio::Reservatorio(){

}

Reservatorio::Reservatorio(Forma* nForma){
	this->forma = nForma;

	this->volumeTotal = this->forma->obterVolumeTotal();
}

unsigned int Reservatorio::obterPorcentagemCheio(double volumeAtual){

	double valor = volumeAtual/this->volumeTotal * 100;

	unsigned int castValor=(unsigned int)valor;

	if(valor!=0 && valor!=100){
		castValor++;
	}

	return castValor;
}

std::ostream& operator<<(std::ostream& out, Reservatorio& r){

   	return out << "Volume total: " << r.volumeTotal;
}