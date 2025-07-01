#include <stdio.h>
float convertTemperature(float celsius) {
    float fahrenheit = (celsius * 9.0 / 5.0) + 32;
    return fahrenheit;
}
int main() {
    float celsius, fahrenheit;
    printf("Enter temperature in Celsius: ");
    scanf("%f", &celsius);
    fahrenheit = convertTemperature(celsius);
    printf("%.2f°C is equal to %.2f°F\n", celsius, fahrenheit);
    return 0;
}
