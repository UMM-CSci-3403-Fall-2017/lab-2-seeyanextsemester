#include <gtest/gtest.h>

#include "disemvowel.h"
char* str;
TEST(Disemvowel, HandleEmptyString) {
str = disemvowel((char*) "");
      	ASSERT_STREQ("", str);
	free(str);
}

TEST(Disemvowel, HandleNoVowels) {
 str = disemvowel((char*)"pqrst");
	ASSERT_STREQ("pqrst",str);
	free(str);
}

TEST(Disemvowel, HandleOnlyVowels) {
str = disemvowel((char*) "aeiouAEIOUOIEAuoiea");
	ASSERT_STREQ("", str);
	free(str);
}

TEST(Disemvowel, HandleMorrisMinnesota) {
str = disemvowel((char*) "Morris, Minnesota");
  ASSERT_STREQ("Mrrs, Mnnst", str);
  free(str);
}

TEST(Disemvowel, HandlePunctuation) {
str = disemvowel((char*) "An (Unexplained) Elephant!");
  ASSERT_STREQ("n (nxplnd) lphnt!", str);
free(str);
}

TEST(Disemvowel, HandleLongString) {
  char* string;
  int size;
  int i;

  size = 50000;
  string = (char*) calloc(size, sizeof(char));
  string[0] = 'x';
  string[1] = 'y';
  string[2] = 'z';
  for (i = 3; i < size-1; ++i) {
    string[i] = 'a';
  }
  string[size-1] = '\0';
  str = disemvowel(string);
  ASSERT_STREQ("xyz", str);
  free(str);
  free(string);
}

int main(int argc, char* argv[]) {
  ::testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}
