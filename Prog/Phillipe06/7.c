float func(float A, int B) {
    float resultado = 1; 
    for(int i = 0; i < B; i++){
        resultado *= A;
    }
    return resultado;
}