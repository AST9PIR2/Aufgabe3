int is_prime(int a){
    //Checking if input < than the smallest prime
    if (a < 2){
        return 0;
    }
    //Checking for every number from 2 to input gives rest
    for (int b=2; b < a; b++){
        if (a%b==0){
            return 0;
        }
    }
    return 1;
}