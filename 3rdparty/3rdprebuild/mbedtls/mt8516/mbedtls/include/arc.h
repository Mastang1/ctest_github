// arc.h

// Licensed under the Apache License, Version 2.0 (the "License");
// you may not use this file except in compliance with the License.
// You may obtain a copy of the License at
//
//     http://www.apache.org/licenses/LICENSE-2.0
//
// Unless required by applicable law or agreed to in writing, software
// distributed under the License is distributed on an "AS IS" BASIS,
// WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
// See the License for the specific language governing permissions and
// limitations under the License.
//
// Copyright 2005-2010 Google, Inc.
// Author: riley@google.com (Michael Riley)
//
// \file
//
// Commonly used Fst arc types.

#ifndef FST_LIB_ARC_H__
#define FST_LIB_ARC_H__

#include <string>

#include "float-weight.h"

#include <iostream>
#include <fstream>
#include <sstream>



namespace fst {

template <class W>
class ArcTpl {
 public:
  typedef W Weight;
  typedef int Label;
  typedef int StateId;

  ArcTpl(Label i, Label o, const Weight& w, StateId s)
      : ilabel(i), olabel(o), weight(w), nextstate(s) {}

  ArcTpl() {}

  static const string &Type(void) {
    static const string type =
        (Weight::Type() == "tropical") ? "standard" : Weight::Type();
    return type;
  }

  Label ilabel;
  Label olabel;
  Weight weight;
  StateId nextstate;
};

typedef ArcTpl<TropicalWeight> StdArc;

}  // namespace fst

#endif  // FST_LIB_ARC_H__
