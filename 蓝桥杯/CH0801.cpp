ostream& operator<<(ostream& os,const zrf_Ratio& tmp){
	os << tmp.num << '/' << tmp.den;
	return os;
}


istream& operator>>(istream& io ,zrf_Ratio& tmp){
	io >> tmp.num >> tmp.den;
	return io;	
}

bool operator==(const zrf_Ratio& tmp1, const zrf_Ratio& tmp2){
	if(tmp1.num == tmp2.num && tmp1.den == tmp2.den)
	return 1;
	return 0;
} 

bool operator<(const zrf_Ratio& tmp1, const zrf_Ratio&tmp2){
	if(tmp1.num * 1.0 / tmp1.den  < tmp2.num * 1.0 / tmp2.den)
	{
		return 1;
	}
	return 0;
}
