char *getinput(){
  int strLen = MAXINPUT;
  int c = getchar();
  int i = 0;
  char *s = malloc((strLen+1)*sizeof(char));
  assert( s != NULL );
  while ( c != '\n' ) {
    s[i] = c;
    i++;
    if ( i >= strLen ) { /* s is not large enough, its length is doubled */
      strLen = 2*strLen;
      s = realloc(s,(strLen+1)*sizeof(char));
      assert( s != NULL );
    }
    c = getchar();
  }
  s[i] = '\0';
  return s;
}


Token *Tokenize(char* input int length)