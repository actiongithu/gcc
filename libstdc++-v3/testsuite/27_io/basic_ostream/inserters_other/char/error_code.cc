// { dg-do run { target c++11 } }

// Copyright (C) 2007-2025 Free Software Foundation, Inc.
//
// This file is part of the GNU ISO C++ Library.  This library is free
// software; you can redistribute it and/or modify it under the
// terms of the GNU General Public License as published by the
// Free Software Foundation; either version 3, or (at your option)
// any later version.

// This library is distributed in the hope that it will be useful,
// but WITHOUT ANY WARRANTY; without even the implied warranty of
// MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
// GNU General Public License for more details.

// You should have received a copy of the GNU General Public License along
// with this library; see the file COPYING3.  If not see
// <http://www.gnu.org/licenses/>.

#include <ostream>
#include <sstream>
#include <system_error>
#include <algorithm>
#include <cstdio>
#include <testsuite_hooks.h>

//   Effects: os << ec.category().name() << ':' << ec.value();
void test()
{
  using namespace std;

  char buf[64];
  error_code e1;
  error_code e2(make_error_code(errc::bad_address));
  string s, s1, s2;

  {
    ostringstream ostr;
    ostr << e1 << endl;
    s1 = ostr.str();

    if (ostr.rdstate() & ios_base::eofbit) 
      VERIFY( false );
  }

  VERIFY( find(s1.begin(), s1.end(), ':') != s1.end() );

  sprintf(buf, "%i", e1.value());
  s = buf;
  VERIFY( s1.find(s) != string::npos );

  {
    ostringstream ostr;
    ostr << e2 << endl;
    s2 = ostr.str();

    if (ostr.rdstate() & ios_base::eofbit) 
      VERIFY( false );
  }

  VERIFY( find(s2.begin(), s2.end(), ':') != s2.end() );

  sprintf(buf, "%i", e2.value());
  s = buf;
  VERIFY( s2.find(s) != string::npos );
}

int 
main()
{
  test(); 
  return 0;
}
