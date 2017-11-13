Medicao::Medicao(Data& nData,double nVolumeAtual){
	this->data = nData;
	this->volumeAtual = nVolumeAtual;
}

std::ostream& operator<<(std::ostream& out, Medicao& m){
	return out << "Data: " << m.data << " Volume atual: " << m.volumeAtual; 
}

bool Medicao::comparador(Medicao i,Medicao j){
	return i.volumeAtual < j.volumeAtual;
}