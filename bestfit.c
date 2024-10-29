#include <stdio.h>
#define max 25

void main() {
    int frag[max], b[max], f[max], i, j, nb, nf, temp;
    static int bf[max], ff[max];

    printf("\nMemory Management Scheme - First Fit");
    printf("\nEnter the number of blocks: ");
    scanf("%d", &nb);
    printf("Enter the number of files: ");
    scanf("%d", &nf);

    printf("\nEnter the size of the blocks:\n");
    for (i = 1; i <= nb; i++) {
        printf("Block %d: ", i);
        scanf("%d", &b[i]);
        bf[i] = 0;
    }

    printf("Enter the size of the files:\n");
    for (i = 1; i <= nf; i++) {
        printf("File %d: ", i);
        scanf("%d", &f[i]);
        ff[i] = 0;
    }

    for (i = 1; i <= nf; i++) {
        for (j = 1; j <= nb; j++) {
            if (bf[j] == 0 && b[j] >= f[i]) {
                ff[i] = j;
                bf[j] = 1;
                break;
            }
        }
        if (ff[i] != 0)
            frag[i] = b[ff[i]] - f[i];
    }

    printf("\nFile_no:\tFile_size:\tBlock_no:\tBlock_size:\tFragmentation\n");
    for (i = 1; i <= nf; i++) {
        if (ff[i] != 0)
            printf("%d\t\t%d\t\t%d\t\t%d\t\t%d\n", i, f[i], ff[i], b[ff[i]], frag[i]);
        else
            printf("%d\t\t%d\t\tNot Allocated\n", i, f[i]);
    }
}
