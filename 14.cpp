#include <iostream>
#include <cmath>
using namespace std;

int main() {
    float Ax, Ay, Az;
    float Bx, By, Bz;

    // Input vector A
    cout << "Input komponen vektor A:\n";
    cout << "A_x = "; cin >> Ax;
    cout << "A_y = "; cin >> Ay;
    cout << "A_z = "; cin >> Az;

    // Input vector B
    cout << "\nInput komponen vektor B:\n";
    cout << "B_x = "; cin >> Bx;
    cout << "B_y = "; cin >> By;
    cout << "B_z = "; cin >> Bz;

    // a) 5A - 3B dan 4A + 7B
    float a1 = 5*Ax - 3*Bx;
    float a2 = 5*Ay - 3*By;
    float a3 = 5*Az - 3*Bz;

    float b1 = 4*Ax + 7*Bx;
    float b2 = 4*Ay + 7*By;
    float b3 = 4*Az + 7*Bz;

    // b) Dot product A · B
    float dot = Ax*Bx + Ay*By + Az*Bz;

    // c) Sudut antara A dan B
    float magA = sqrt(Ax*Ax + Ay*Ay + Az*Az);
    float magB = sqrt(Bx*Bx + By*By + Bz*Bz);

    float angle = acos(dot / (magA * magB)) * 180.0 / M_PI;

    // d) Jarak antara A dan B
    float distance = sqrt(pow(Ax - Bx, 2) + pow(Ay - By, 2) + pow(Az - Bz, 2));

    // e) A × B
    float cx = Ay*Bz - Az*By;
    float cy = Az*Bx - Ax*Bz;
    float cz = Ax*By - Ay*Bx;

    // f) B × A = -(A × B)
    float dx = -cx;
    float dy = -cy;
    float dz = -cz;

    // g) ||A × B||
    float magAxB = sqrt(cx*cx + cy*cy + cz*cz);

    // h) ||B × A||
    float magBxA = sqrt(dx*dx + dy*dy + dz*dz);

    // Output
    cout << "\n=== HASIL PERHITUNGAN ===\n";

    cout << "a) 5A - 3B = (" << a1 << ", " << a2 << ", " << a3 << ")\n";
    cout << "   4A + 7B = (" << b1 << ", " << b2 << ", " << b3 << ")\n";

    cout << "\nb) A · B = " << dot << endl;
    cout << "c) Sudut A dan B = " << angle << " derajat\n";
    cout << "d) Jarak A dan B = " << distance << endl;

    cout << "\ne) A × B = (" << cx << ", " << cy << ", " << cz << ")\n";
    cout << "f) B × A = (" << dx << ", " << dy << ", " << dz << ")\n";

    cout << "\ng) ||A × B|| = " << magAxB << endl;
    cout << "h) ||B × A|| = " << magBxA << endl;

    return 0;
}
