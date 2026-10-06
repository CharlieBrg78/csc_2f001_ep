#include <stdio.h>
#include <stdlib.h>


int sort_get_index(float tab[], int top, float val) {
    for(int i=0; i<top; i+=1) {
        if (tab[i] > val) {
            return i;
        }
    }
    return top;
}

void sort_insert_at(float tab[], int i, int top, float val) {
    for (int n = top; n > i; n-=1) {
        tab[n] = tab[n-1];
    }
    tab[i] = val;
}

void sort_insert(float tab[], int top, float val) {
    int i = sort_get_index(tab, top, val);
    sort_insert_at( tab, i, top, val);
}

int nb_columns() {
    return 32;
}

int nb_lines() {
    return 16;
}

void grid_init(char grid[], char pixel) {
    for (int i=0; i<nb_columns()*nb_lines();i++){
        grid[i] = pixel;
    }
}

void grid_display(char grid[]) {
    for (int i=0;i<nb_lines();i++) {
        for (int j=0;j<nb_columns();j++) {
            printf("%c", grid[i*nb_columns()+j]);
        }
        printf("\n");
    }
}

void plot_point(char grid[], int x, int y, char pixel) {
    if (x>nb_columns()-1 || x<0 || y>nb_lines()-1 || y<0) {
        printf("ERROR \n");
        exit(EXIT_FAILURE);
    }
    grid[ (nb_lines()-y-1) * nb_columns() + x] = pixel;
}

void plot_vline(char grid[], int x, float fy0, float fy1, char pixel) {
    int y0 = (int)(fy0+0.5);
    int y1 = (int)(fy1+0.5);
    if(y0 == fy0 + 0.5) {
        y0 -= 1;
    }

    for(int i=y0; i<=y1; i+=1) {
        plot_point(grid, x, i, pixel);
}
}

struct point {
    float x;
    float y;
};

void plot_poly_sweep(char grid[], struct point arr[], int num_arr, int x, char pixel) {
    float vlines[num_arr * 4];
    int top = 0;

    int j = num_arr - 1;
    for (int i = 0; i < num_arr; i++) {
        if ((arr[i].x <= x && x < arr[j].x) || (arr[j].x <= x && x < arr[i].x)) {
            float h = arr[i].y + (x - arr[i].x) * (arr[j].y - arr[i].y) / (arr[j].x - arr[i].x);
            sort_insert(vlines, top, h);
            top++;
        }
        j = i;
    }

    printf("sweep %d:", x);
    for (int k = 0; k < top; k++) {
        printf(" %f", vlines[k]);
    }
    printf("\n");

    for (int k = 0; k < top; k += 2) {
        plot_vline(grid, x, vlines[k], vlines[k+1], pixel);
    }
}

void plot_poly (char grid[], struct point arr[], int num_arr, char pixel) {
    for (int x=0; x<nb_columns(); x++) {
        plot_poly_sweep(grid, arr, num_arr, x, pixel);
    }
}

int main() {
    char grid[nb_columns()*nb_lines()];
    struct point p[] = {{ 2, 13 }, { 10, 13 }, { 30, 7 }, { 10, 1 }, { 2, 1 }, { 18, 7 }};
    grid_init(grid, ' ');
    plot_poly(grid, p, 6, '-');
    grid_display(grid);
    return 0;
}