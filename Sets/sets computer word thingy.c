//Bit Vector Array
SET* Union(SET* A, SET* B){
	SET *C = calloc(1, sizeof(SET));
	int i;
	for(i = 0; i < 8; i++){
		C[i] = A[i] | B[i]; 
	}
	return C;
}

SET* Intersection(SET* A, SET* B){
	SET *C = calloc(1, sizeof(SET));
	int i;
	for(i = 0; i < 8; i++){
		C[i] = A[i] & B[i]; 
	}
	return C;
}

SET* Difference(SET* A, SET* B){
	SET *C = calloc(1, sizeof(SET));
	int i;
	for(i = 0; i < 8; i++){
		C[i] = A[i] &~ B[i]; 
	}
	return C;
}

void insert(SET *A, int index){
	if(index >= 0 && index < 8){
		*A[i] = true;
	}
}

//Bit Vector Computer Word
SET Union(SET A, SET B){
	return A | B;
}

SET Intersection(SET A, SET B){
	return A & B;
}

SET Difference(SET A, SET B){
	return A &~ B;
}

void insert(SET *A, int index){
	if(index >= 0 && index < sizeof(byte)*8){
		*A = *A | (1 << index);
	}
}



