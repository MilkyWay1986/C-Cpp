/*

Задача : минимальная строка
  Дано 3 строки разделенные пробелами( состоят из строчных латинских букв )
  в стандартный вывод вывести лексиграфическую минимальную из этих строк .


  План тестирования :
    1. Все три строчки разные : alfa beta gamma
                                beta alfa gamma
                                beta gamma alfa

    2. Две одинаковые строки :  alfa beta alfa
                                beta alfa alfa
                                alfa alfa beta

    3. Все три строки одинаковые : alfa alfa alfa




bool IsPalindrom(string s) {
  for (size_t i = 0; i < s.size() / 2; ++i) {
      if (s[i] != s[s.size() - i - 1]) {
          return false;
      }
  }
return true;
}

void UpdateIfGreater(int a, int& b) {
    if (a > b) {
        b = a;
    }
}


vector<int> Reversed(const vector<int>& input) {
  auto seq = input;
  for (int i = 0; i < seq.size() / 2; ++i) {
      auto tmp = seq[i];
      seq[i] = seq[seq.size() - 1 - i];
      seq[seq.size() - 1 - i] = tmp;
  }
  return seq;
}




























*/
