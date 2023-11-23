import 'dart:math';

void main() {
  double a = 1;
  double b = -5;
  double c = 6;

  double discriminant = b * b - 4 * a * c;

  if (discriminant > 0) {
    double root1 = (-b + sqrt(discriminant)) / (2 * a);
    double root2 = (-b - sqrt(discriminant)) / (2 * a);
    print("Root 1: $root1");
    print("Root 2: $root2");
  } else if (discriminant == 0) {
    double root = -b / (2 * a);
    print("Root: $root");
  } else {
    double realPart = -b / (2 * a);
    double imaginaryPart = sqrt(-discriminant) / (2 * a);
    print("Root 1: $realPart + ${imaginaryPart}i");
    print("Root 2: $realPart - ${imaginaryPart}i");
  }
}
// note when a b and c are replaced with coeffcients of whatever the specfic equation may be,
// and the program will calculate and display the roots
