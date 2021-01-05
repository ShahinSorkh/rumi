#include "base.h"
#include <ostream>

#include "parser/parser.h"

int main(int argc, char **argv) {
  CompileContext cc(argc, argv);

  for (Source *s : cc.sources) {
    cc.debug(Verbosity::LOW) << *s << endl;
  }

  cc.debug(Verbosity::MEDIUM) << "Context created." << endl;

  for(Source *s: cc.sources){
    cc.load(s);
    ParseResult t;
    t = cc.parser.parseTop(s);
    while(t){
      cc.debug(Verbosity::NONE) << t << endl;
      t = cc.parser.parseTop(s, t.token->epos + 1);
    }
  }


  return 0;
}