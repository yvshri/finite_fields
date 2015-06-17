std::vector<bool> decToBin(mpz_t num_){
    mpz_t num, quo, rem;
    mpz_inits(num, quo, rem, NULL);
    mpz_set(num, num_);
    cin >> num;
    std::vector<bool> num_bin;
    num_bin.clear();
    while(mpz_cmp_ui(num, 0) != 0){
        mpz_fdiv_qr_ui (quo, rem, num, 2);        
        num_bin.push_back(bool(mpz_get_ui(rem)));
        mpz_set(num, quo);
    }
    std::reverse(num_bin.begin(), num_bin.end());
    mpz_clears(quo, rem, num, NULL);
    // for (std::vector<bool>::iterator i = num_bin.begin(); i != num_bin.end(); ++i){
    //     cout << *i << " ";
    // }
    return num_bin;
}