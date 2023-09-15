#include <bits/stdc++.h>
#include <cmath>
using namespace std;

long int digitsone(long int n) {
  int tens = n / 10;
  int units = n % 10;

  if (tens == units) {
    return n;
  } else if (tens > units) {
    return tens * 11;
  } else {
    return (tens + 1) * 11;
  }
}

long int digitstwo(long int n) {
  int hundreds = n / 100;
  int tens = (n / 10) % 10;
  int units = n % 10;

  if (hundreds == units) {
    return n;
  } else if (hundreds > units) {
    return hundreds * 100 + tens * 10 + hundreds;
  } else {
    return hundreds * 100 + tens * 10 + (hundreds + 10);
  }
}

long int digitsthree(long int n) {
  int thousands = n / 1000;
  int hundreds = (n / 100) % 10;
  int tens = (n / 10) % 10;
  int units = n % 10;
  int middle = digitsone(hundreds * 10 + tens);
  int midtens = digitsone(hundreds * 10 + tens + 1);

  if (thousands == units) {
    return middle * 10 + thousands * 1000 + units;
  } else if (thousands > units) {
    return thousands * 1000 + thousands + middle * 10;
  } else {
    return thousands * 1000 + (thousands) + midtens * 10;
  }
}

long int digitsfour(long int n) {
  int tenthousands = n / 10000;
  int thousands = (n / 1000) % 10;
  int hundreds = (n / 100) % 10;
  int tens = (n / 10) % 10;
  int units = n % 10;
  int middle = digitstwo(thousands * 100 + hundreds * 10 + tens);
  int midtens = digitstwo(thousands * 100 + hundreds * 10 + tens + 1);

  if (tenthousands == units) {
    return tenthousands * 10000 + units + middle * 10;
  } else if (tenthousands > units) {
    return tenthousands * 10000 + tenthousands + middle * 10;
  } else {
    return tenthousands * 10000 + tenthousands + midtens * 10;
  }
}

long int digitsfive(long int n) {
  int lakhs = n / 100000;
  int tenthousands = (n / 10000) % 10;
  int thousands = (n / 1000) % 10;
  int hundreds = (n / 100) % 10;
  int tens = (n / 10) % 10;
  int units = n % 10;
  int middle =
      digitsthree(tenthousands * 1000 + thousands * 100 + hundreds * 10 + tens);
  int midtens = digitsthree(tenthousands * 1000 + thousands * 100 +
                            hundreds * 10 + tens + 1);

  if (lakhs == units) {
    return lakhs * 100000 + units + middle * 10;
  } else if (lakhs > units) {
    return lakhs * 100000 + lakhs + middle * 10;
  } else {
    return lakhs * 100000 + lakhs + midtens * 10;
  }
}

long int digitssix(long int n) {
  long int tenlakhs = n / 1000000;

  long int lakhs = (n / 100000) % 10;
  long int tenthousands = (n / 10000) % 10;
  long int thousands = (n / 1000) % 10;
  long int hundreds = (n / 100) % 10;
  long int tens = (n / 10) % 10;
  long int units = n % 10;
  long int middle = digitsfour(lakhs * 10000 + tenthousands * 1000 +
                          thousands * 100 + hundreds * 10 + tens);
  long int midtens = digitsfour(lakhs * 10000 + tenthousands * 1000 +
                           thousands * 100 + hundreds * 10 + tens + 1);

  

  if (tenlakhs == units) {
    return tenlakhs * 1000000 + units + (middle * 10);
  } else if (tenlakhs > units) {
    return tenlakhs * 1000000 + tenlakhs + (middle * 10);
  } else {
    return tenlakhs * 1000000 + tenlakhs + (midtens * 10);
  }
}

long int digitsseven(long int n) {
  int crores = n / 10000000;
  int tenlakhs = (n / 1000000) % 10;
  int lakhs = (n / 100000) % 10;
  int tenthousands = (n / 10000) % 10;
  int thousands = (n / 1000) % 10;
  int hundreds = (n / 100) % 10;
  int tens = (n / 10) % 10;
  int units = n % 10;
  int middle =
      digitsfive(tenlakhs * 100000 + lakhs * 10000 + tenthousands * 1000 +
                 thousands * 100 + hundreds * 10 + tens);
  int midtens =
      digitsfive(tenlakhs * 100000 + lakhs * 10000 + tenthousands * 1000 +
                 thousands * 100 + hundreds * 10 + tens + 1);

  if (crores == units) {
    return crores * 10000000 + units + middle * 10;
  } else if (crores > units) {
    return crores * 10000000 + crores + middle * 10;
  } else {
    return crores * 10000000 + crores + midtens * 10;
  }
}

void next_palindrome(long int n) {

  int digits = log10(n);

  if (n == 1) {

  } else if (n < 9) {
    cout << n << "\n";
  } else if (n == 9) {
    cout << 11 << "\n";
  } else if (digits == 1) {
    cout << digitsone(n) << "\n";
  } else if (digits == 2) {
    cout << digitstwo(n) << "\n";
  } else if (digits == 3) {

    cout << digitsthree(n) << "\n";
  } else if (digits == 4) {
    cout << digitsfour(n) << "\n";
  } else if (digits == 5) {
    cout << digitsfive(n) << "\n";
  } else if (digits == 6) {
    cout << digitssix(n) << "\n";
  } else if (digits == 7) {
    cout << digitsseven(n) << "\n";
  }
}

int main() {
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(NULL);

  long int t;
  cin >> t;
  if (t > 0) {
    int arr[t];

    for (int i = 0; i < t; i++) {
      cin >> arr[i];
    }
    for (int j = 0; j < t; j++) {

      next_palindrome(arr[j] + 1);
    }
  }

  return 0;
}