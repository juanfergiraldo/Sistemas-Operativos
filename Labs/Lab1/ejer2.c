/* 2. Diseñar un programa que calcule el área y el perímetro de un triángulo
    rectángulo dada la  base  y  la  altura  (sus  dos  catetos).*/
    #include <stdio.h>
    #include <math.h>

    double area(double b, double h);
    double perimetro (double b, double h);

    int main() {
      double b;
      double h;
      printf("Por favor ingrese el tamaño de la base y altura del triángulo: ");
      scanf("%lf %lf", &b, &h);
      printf("El área del triángulo de base %.2lf cm y altura %.2lf cm, es: %.2lf\n", b, h, area(b, h));
      printf("El perimetro del triángulo de base %.2lf cm y altura %.2lf cm, es: %.2lf\n", b, h, perimetro(b, h));

      return 0;
    }

      double area(double b, double h){
        double a;
        a = b * h;
        return a;
      }

      double perimetro (double b, double h){
          double p;
          double hipo;
          hipo = sqrt(pow(b, 2) + pow(h, 2));
          p = b + h + hipo;
          return p;
      }
