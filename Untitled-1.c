#include <stdio.h>

int main() {
    FILE *fp;
    int data;
    int count = 0;
    int max, min;
    int sum = 0;
    float average;

    fp = fopen("data.txt", "r");

    if (fp == NULL) {
        printf("Cannot open file data.txt\n");
        return 1;
    }

    while (fscanf(fp, "%d", &data) != EOF) {
        if (count == 0) {
            max = data;
            min = data;
        }

        if (data > max) {
            max = data;
        }

        if (data < min) {
            min = data;
        }

        sum = sum + data;
        count++;
    }

    fclose(fp);

    if (count > 0) {
        average = (float)sum / count;

        printf("จำนวนข้อมูล = %d\n", count);
        printf("ค่าสูงสุด = %d\n", max);
        printf("ค่าต่ำสุด = %d\n", min);
        printf("ค่าเฉลี่ย = %.2f\n", average);
    } else {
        printf("ไม่มีข้อมูลในไฟล์\n");
    }

    //ทดลองเพิ่ม

    return 0;
}