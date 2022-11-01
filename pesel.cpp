#include <iostream>
#include <string>

bool isValidPesel(std::string pesel)
{
  // sprawdzanie dlugosci
  // 06320906088
  if (pesel.size() != 11)
  {
    std::cerr << " zła długość peselu" << std::endl;
    return false;
  }
  // sprawdzanie zawartosci
  for (char x : pesel)
  {
    if (!(x >= '0' && x <= '9'))
    {
      std::cerr << "pesel zawiera niewłasciwe znaki" << std::endl;
      return false;
    }
  }
  // sprawdzanie cyfry konttolnej
  int a[10];
  int atotal = 0;
  int liczbakont;
  a[0] = (pesel[0] - '0') * 1;
  a[1] = (pesel[1] - '0') * 3;
  a[2] = (pesel[2] - '0') * 7;
  a[3] = (pesel[3] - '0') * 9;
  a[4] = (pesel[4] - '0') * 1;
  a[5] = (pesel[5] - '0') * 3;
  a[6] = (pesel[6] - '0') * 7;
  a[7] = (pesel[7] - '0') * 9;
  a[8] = (pesel[8] - '0') * 1;
  a[9] = (pesel[9] - '0') * 3;

  for (int ax : a)
  {
    atotal += (ax % 10);
  }
  liczbakont = (10 - (atotal % 10)) % 10;

  if (liczbakont != pesel[10] - '0')
  {
    std::cerr << "cyfra kontrolna sie nie zgadza" << std::endl;
    return false;
  }
  return true;
}

int main(int, char **)
{
  std::string pesel;
  do
  {
    std::cin >> pesel;

    if (!isValidPesel(pesel))
    {
      std::cerr << "niepoprawny PESEL, wpisz jeszcze raz" << std::endl;
      continue;
    }

  } while (false);

  // sprawdzamy płeć jeśli w peselu wszystko gra
  if ((pesel[9] - '0') % 2 == 0)
  {
    std::cout << "płeć rźeńska" << std::endl;
  }
  else
  {
    std::cout << "płeć męśka" << std::endl;
  }
  // pobieramy date urodzenia
  int MM = (pesel[2] - '0') * 10 + (pesel[3] - '0');
  int day = (pesel[4] - '0') * 10 + (pesel[5] - '0');
  int month = MM % 20;
  // yearcode jako nazędzie
  int yearcode = MM - month;
  // year1 jako pierwsze 2 cyfry roku, czyli stulecie
  int year1;
  std::string months[12] = {"styczeń", "luty", "marzec", "kwieceń", "maj", "czerwiec", "lipiec", "sierpień", "wrzesień", "październik", "listopad", "grudzień"};

  if (yearcode == 80)
  {
    year1 = 1800;
  }
  else if (yearcode == 0)
  {
    year1 = 1900;
  }
  else if (yearcode == 20)
  {
    year1 = 2000;
  }
  else if (yearcode == 40)
  {
    year1 = 2100;
  }
  else if (yearcode == 60)
  {
    year1 = 2200;
  }

  int year = year1 + (pesel[0] - '0') * 10 + (pesel[1] - '0');

  std::cout << "data urodzenia to: " << day << "." << months[month - 1] << "." << year << " roku" << std::endl;

  return 0;
}
