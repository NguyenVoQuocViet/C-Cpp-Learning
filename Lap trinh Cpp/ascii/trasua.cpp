#include <iostream>
#include <vector>
#include <cmath>
#include <cstring>
#include <thread>
#include <chrono>

using namespace std;

void trasua_ascii() {
    float A = 0; 
    float B = 0.6; // Độ nghiêng vừa phải để thấy rõ 3D
    float z[1760];
    char b[1760];
    string label = "TRASUA";

    printf("\x1b[?25l\x1b[2J");

    for (;;) {
        memset(b, 32, 1760);
        memset(z, 0, 7040);

        float cosA = cos(A), sinA = sin(A);
        float cosB = cos(B), sinB = sin(B);

        for (float h = -2.8; h < 1.5; h += 0.05) {
            for (float theta = 0; theta < 6.28; theta += 0.04) {
                float cost = cos(theta), sint = sin(theta);
                
                float R = 0.7 - (h * 0.15); 
                
                float x0 = R * cost;
                float y0 = h * 1.5; 
                float z0 = R * sint;

                float x1 = x0 * cosA + z0 * sinA;
                float z1 = -x0 * sinA + z0 * cosA;

                float x_final = x1;
                float y_final = y0 * cosB - z1 * sinB;
                float z_final = y0 * sinB + z1 * cosB + 10; 

                float ooz = 1 / z_final;

                int x = 40 + (int)(45 * ooz * x_final * 2.0);
                int y = 12 + (int)(22 * ooz * y_final); 

                int o = x + 80 * y;
                if (y >= 0 && y < 22 && x >= 0 && x < 80 && ooz > z[o]) {
                    z[o] = ooz;
                    bool is_label = false;
                    if (h > -0.3 && h < 0.3 && theta > 2.6 && theta < 3.7) {
                        int char_idx = (int)((theta - 2.6) / (1.1 / label.length()));
                        if (char_idx >= 0 && char_idx < (int)label.size()) {
                            b[o] = label[char_idx];
                            is_label = true;
                        }
                    }
                    if (!is_label) {
                        float L = cost * cosA - sint * sinA; 
                        int l_idx = (L + 1) * 4;
                        b[o] = ".,-~:;=!*#$@"[l_idx > 0 ? (l_idx < 12 ? l_idx : 11) : 0];
                    }
                }
            }
        }

        for (float h_s = -4.2; h_s < -2.8; h_s += 0.03) {
            for (float phi = 0; phi < 6.28; phi += 1.0) {
                float x0 = 0.08 * cos(phi) + 0.3; 
                float z0 = 0.08 * sin(phi) + 0.3;
                float y0 = h_s * 1.5;

                float x1 = x0 * cosA + z0 * sinA;
                float z1 = -x0 * sinA + z0 * cosA;
                float y_f = y0 * cosB - z1 * sinB;
                float z_f = y0 * sinB + z1 * cosB + 10;
                float ooz = 1 / z_f;

                int x = 40 + (int)(45 * ooz * x1 * 2.0), y = 12 + (int)(22 * ooz * y_f);
                if (x >= 0 && x < 80 && y >= 0 && y < 22 && ooz > z[x + 80 * y]) {
                    z[x + 80 * y] = ooz; b[x + 80 * y] = 'H'; 
                }
            }
        }

        // 3. VÀNH ĐÁY LY
        for (float t = 0; t < 6.28; t += 0.02) {
            float R_bot = 0.7 - (-2.8 * 0.15);
            float x0 = R_bot * cos(t), y0 = -2.8 * 1.5, z0 = R_bot * sin(t);
            float x1 = x0 * cosA + z0 * sinA;
            float z1 = -x0 * sinA + z0 * cosA;
            float y_f = y0 * cosB - z1 * sinB;
            float z_f = y0 * sinB + z1 * cosB + 10;
            float ooz = 1 / z_f;
            int x = 40 + (int)(45 * ooz * x1 * 2.0), y = 12 + (int)(22 * ooz * y_f);
            if (x >= 0 && x < 80 && y >= 0 && y < 22 && ooz > z[x + 80 * y]) {
                z[x + 80 * y] = ooz; b[x + 80 * y] = '=';
            }
        }

        printf("\x1b[H");
        for (int k = 0; k < 1761; k++) {
            putchar(k % 80 ? b[k] : 10);
        }

        A += 0.08;
        this_thread::sleep_for(chrono::milliseconds(30));
    }
}

int main() {
    trasua_ascii();
    return 0;
}