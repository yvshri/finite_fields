# finite_fields
<h3>Installing gmplib:</h3>
1. Download gmp source tar file from <a href="https://gmplib.org/">Download</a>
2. Extract tar and go into the gmp directory
3. sudo ./configure --enable-cxx
4. sudo make
5. sudo make check
6. sudo make install

<h3>Compile</h3>
1. Compile .hxx first, for eg: 
g++ ZZ_p.hxx -lgmpxx -lgmp
ignore error in compilation like undefind reference to main
2. Compile the source file
g++ test_zz_p.hxx -lgmpxx -lgmp

 
