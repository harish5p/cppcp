#include <bits/stdc++.h>
#include <cmath>
using namespace std;

long int digitsone(long int n) {
  int tens = n / 10;
  int units = n % 10;
  int result;

  if (tens == units) {
    result = n;
  } else if (tens > units) {
    result = tens * 11;
  } else {
    result = (tens + 1) * 11;
  }
  // cout << "Result for digitsone " <<result << endl;

  if (result / 10 != result % 10) {
    result = result + 1;
  }

  if (result >= 100) {
    result = 100;
  }
  // cout << "Updated result for digitsone: " << result << endl;
  return result;
}

long int digitstwo(long int n) {
  int hundreds = n / 100;
  int tens = (n / 10) % 10;
  int units = n % 10;
  int result;

  if (hundreds == units) {
    result = n;
  } else if (hundreds > units) {
    result = hundreds * 100 + tens * 10 + hundreds;
  } else {
    result = hundreds * 100 + tens * 10 + (hundreds + 10);
  }
  // cout << "Result for digitstwo " <<result << endl;

  if (result / 100 != result % 10) {
    result = result + 1;
  }

  if (result >= 1000) {
    result = 1000;
  }
  // cout << "Updated result for digitstwo: " << result << endl;
  return result;
}

long int digitsthree(long int n) {
  int thousands = n / 1000;
  int hundreds = (n / 100) % 10;
  int tens = (n / 10) % 10;
  int units = n % 10;
  int middle = digitsone(hundreds * 10 + tens);
  int midtens = digitsone(hundreds * 10 + tens + 1);
  int result;

  if (thousands == units) {
    result = middle * 10 + thousands * 1000 + units;

  } else if (thousands > units) {
    result = thousands * 1000 + thousands + middle * 10;

  } else {
    result = thousands * 1000 + (thousands) + midtens * 10;
  }
  // cout << "Result for digitsthree " <<result << endl;

  if (result / 1000 != result % 10) {
    result = result + 1;
  }

  if (result >= 10000) {
    result = 10000;
  }
  // cout << "Updated result for digitsthree: " << result << endl;
  return result;
}

long int digitsfour(long int n) {
  int tenthousands = n / 10000;
  int thousands = (n / 1000) % 10;
  int hundreds = (n / 100) % 10;
  int tens = (n / 10) % 10;
  int units = n % 10;
  int middle = digitstwo(thousands * 100 + hundreds * 10 + tens);
  int midtens = digitstwo(thousands * 100 + hundreds * 10 + tens + 1);
  int result;

  if (tenthousands == units) {

    result = tenthousands * 10000 + units + middle * 10;
  } else if (tenthousands > units) {
    result = tenthousands * 10000 + tenthousands + middle * 10;
  } else {
    result = tenthousands * 10000 + tenthousands + midtens * 10;
  }
  // cout << "Result for digitsfour " <<result << endl;

  if (result / 10000 != result % 10) {
    result = result + 1;
  }

  if (result >= 100000) {
    result = 100000;
  }
  // cout << "Updated result for digitsfour: " << result << endl;
  return result;
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
  int result;

  if (lakhs == units) {
    result = lakhs * 100000 + units + middle * 10;
  } else if (lakhs > units) {
    result = lakhs * 100000 + lakhs + middle * 10;
  } else {
    result = lakhs * 100000 + lakhs + midtens * 10;
  }
  // cout << "Result for digitsfive " <<result << endl;

  if (result / 100000 != result % 10) {
    result = result + 1;
  }

  if (result >= 1000000) {
    result = 1000000;
  }
  // cout << "Updated result for digitsfive: " << result << endl;
  return result;
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
  long int result;

  if (tenlakhs == units) {
    result = tenlakhs * 1000000 + units + (middle * 10);
  } else if (tenlakhs > units) {
    result = tenlakhs * 1000000 + tenlakhs + (middle * 10);
  } else {
    result = tenlakhs * 1000000 + tenlakhs + (midtens * 10);
  }

  // cout << "Result for digitssix " <<result << endl;

  if (result / 1000000 != result % 10) {
    result = result + 1;
  }

  if (result >= 10000000) {
    result = 10000000;
  }
  // cout << "Updated result for digitssix: " << result << endl;
  return result;
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
  int result;

  if (crores == units) {
    result = crores * 10000000 + units + middle * 10;
  } else if (crores > units) {
    result = crores * 10000000 + crores + middle * 10;
  } else {
    result = crores * 10000000 + crores + midtens * 10;
  }

  // cout << "Result for digitsseven " <<result << endl;

  if (result / 10000000 != result % 10) {
    result = result + 1;
  }

  if (result >= 100000000) {
    result = 100000000;
  }
  // cout << "Updated result for digitsseven: " << result << endl;
  return result;
}

// void next_palindrome(long int n) {

//   int digits = log10(n);

//   if (n == 1) {

//   } else if (n < 9) {
//     cout << n << "\n";
//   } else if (n == 9) {
//     cout << 11 << "\n";
//   } else if (digits == 1) {
//     cout << digitsone(n) << "\n";
//   } else if (digits == 2) {
//     cout << digitstwo(n) << "\n";
//   } else if (digits == 3) {

//     cout << digitsthree(n) << "\n";
//   } else if (digits == 4) {
//     cout << digitsfour(n) << "\n";
//   } else if (digits == 5) {
//     cout << digitsfive(n) << "\n";
//   } else if (digits == 6) {
//     cout << digitssix(n) << "\n";
//   } else if (digits == 7) {
//     cout << digitsseven(n) << "\n";
//   }
// }

int next_palindrome(long int n) {

  int digits = log10(n);

  if (n == 1) {

  } else if (n < 9) {
    return n;
  } else if (n == 9) {
    return 11;
  } else if (digits == 1) {
    return digitsone(n);
  } else if (digits == 2) {
    return digitstwo(n);
  } else if (digits == 3) {

    return digitsthree(n);
  } else if (digits == 4) {
    return digitsfour(n);
  } else if (digits == 5) {
    return digitsfive(n);
  } else if (digits == 6) {
    return digitssix(n);
  } else if (digits == 7) {
    return digitsseven(n);
  }
}

bool isPali(int num) {
  int n = num;
  int rev = 0;
  while (num > 0) {
    int dig = num % 10;
    rev = rev * 10 + dig;
    num = num / 10;
  }
  if (n == rev) {
    return 1;
  } else {
    return 0;
  }
}

int main() {
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(NULL);

  for (int i = 1; i <= 10000000; i++) {
    int x = next_palindrome(i);
    if (isPali(x)){
      cout << x << endl;

    } else {
      cout << x << "is not a  pali"<< endl;
      break;
    }
  }

  // long int t;
  // cin >> t;
  // if (t > 0) {
  //   long int arr[t];

  //   for (int i = 0; i < t; i++) {
  //     cin >> arr[i];
  //   }
  //   for (int j = 0; j < t; j++) {

  //     next_palindrome(arr[j] + 1);
  //   }
  // }

  return 0;
}