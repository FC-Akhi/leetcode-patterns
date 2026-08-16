char s[] = "hello";

printf("%zu\n", sizeof(s)); // 6, includes '\0'
printf("%zu\n", strlen(s)); // 5, excludes '\0'