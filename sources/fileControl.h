void saveValue(int value) {
    FILE *f = fopen("data.mcal", "w");
    if (f != NULL) {
        fprintf(f, "%d", value);
    } else {
      FILE *f = fopen("data.mcal", "w");
      fprintf(f, "%d", value);
    }
    fclose (f);
    //  printf("Saved!\n");
}

void loadValue() {
    FILE *f = fopen("data.mcal", "r");
    if (f != NULL) {
      fscanf(f, "%d", &ioMode);
    } else {
      FILE *f = fopen("data.mcal", "w");
      fprintf(f, "0");
    }
    fclose (f);
}
