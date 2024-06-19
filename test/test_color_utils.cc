#include <FastLED_IO.h>
#include <unity.h>

void test_blendColors(void) {
  CRGB firstColor  = CRGB::Black;
  CRGB secondColor = CRGB::White;
  CRGB mixedColor  = blendColors(firstColor, secondColor, 127);
  TEST_ASSERT_EQUAL(mixedColor.r, 127);
  TEST_ASSERT_EQUAL(mixedColor.b, 127);
  TEST_ASSERT_EQUAL(mixedColor.g, 127);
}

int runUnityTests(void) {
  UNITY_BEGIN();
  RUN_TEST(test_blendColors);
  return UNITY_END();
}

void setup() {
  runUnityTests();
}

void loop() {
}
