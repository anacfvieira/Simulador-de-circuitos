#include "porta.h"

///
/// AS PORTAS
///

/// Porta NOT

class PortaNOT: public Porta
{
public:
  // Construtor default (fixa o numero de entradas da porta como sendo 1)
  PortaNOT(): Porta(1) {}
  // DEMAIS FUNCOES DA PORTA
  //Clonagem da porta Not
  ptr_Porta clone() const override{
      return new PortaNOT(*this);
  }
  //Retorno do nome da porta
  std::string getName() const override{
      return "NT";
  }
  //Simulador da porta Not
  bool simular(const std::vector<bool3S>& in_port) override{
      if(in_port.size()>0 && in_port.size()==static_cast<size_t>(getNumInputs())){
          if(in_port[0] == bool3S::TRUE){
              setOutput(bool3S::FALSE);
          }
          else if(in_port[0] == bool3S::FALSE){
              setOutput(bool3S::TRUE);
          }
          else{
              setOutput(bool3S::UNDEF);
          }
          return true;
      }
      else{
          setOutput(bool3S::UNDEF);
          return false;
      }
  }
};

/// Porta AND

class PortaAND: public Porta
{
public:
  // PortaAND nao tem construtor default: sempre deve ser informado o num de entradas
  PortaAND() = delete;
  // Construtor especifico (recebe como parametro o numero de entradas da porta)
  // Se o parametro for invalido, faz Nin_port=0
  PortaAND(int NI): Porta(NI)
  {
    if (NI<2) Nin_port=0;
  }
  // DEMAIS FUNCOES DA PORTA
  //Clonagem da porta And
  ptr_Porta clone() const override{
      return new PortaAND(*this);
  }
  //Retorno do nome da porta
  std::string getName() const override{
      return "AN";
  }
  //Simulador da porta And
  bool simular(const std::vector<bool3S>& in_port) override{
      if(in_port.size()>0 && in_port.size()==static_cast<size_t>(getNumInputs())){
          if(in_port[0] == bool3S::UNDEF){setOutput(bool3S::UNDEF); return false;}
          bool3S result = in_port[0];
          for(size_t i=1; i<in_port.size(); ++i){
              if(in_port[i]==bool3S::UNDEF){setOutput(bool3S::UNDEF); return false;}
              if(in_port[i]==bool3S::FALSE){result=bool3S::FALSE; break;}
          }
          setOutput(result);
          return true;
      }
      else{
          setOutput(bool3S::UNDEF);
          return false;
      }
  }
};

/// Porta NAND

class PortaNAND: public Porta
{
public:
  // PortaNAND nao tem construtor default: sempre deve ser informado o num de entradas
  PortaNAND() = delete;
  // Construtor especifico (recebe como parametro o numero de entradas da porta)
  // Se o parametro for invalido, faz Nin_port=0
  PortaNAND(int NI): Porta(NI)
  {
    if (NI<2) Nin_port=0;
  }
  // DEMAIS FUNCOES DA PORTA
  //Clonagem da porta NAnd
  ptr_Porta clone() const override{
      return new PortaNAND(*this);
  }
  //Retorno do nome da porta
  std::string getName() const override{
      return "NA";
  }
  //Simulador da porta NAnd
  bool simular(const std::vector<bool3S>& in_port) override{
      if(in_port.size()>0 && in_port.size()==static_cast<size_t>(getNumInputs())){
          PortaAND pAnd(in_port.size());
          if(pAnd.simular(in_port)){
              bool3S andResult = pAnd.getOutput();
              bool3S result = (andResult == bool3S::TRUE)? bool3S::FALSE : bool3S::TRUE;
              setOutput(result);
              return true;
          }else{
              setOutput(bool3S::UNDEF);
              return false;
          }
      }
      else{
          setOutput(bool3S::UNDEF);
          return false;
      }
  }
};

/// Porta OR

class PortaOR: public Porta
{
public:
  // PortaOR nao tem construtor default: sempre deve ser informado o num de entradas
  PortaOR() = delete;
  // Construtor especifico (recebe como parametro o numero de entradas da porta)
  // Se o parametro for invalido, faz Nin_port=0
  PortaOR(int NI): Porta(NI)
  {
    if (NI<2) Nin_port=0;
  }
  // DEMAIS FUNCOES DA PORTA
  //Clonagem da porta Or
  ptr_Porta clone() const override{
      return new PortaOR(*this);
  }
  //Retorno do nome da porta
  std::string getName() const override{
      return "OR";
  }
  //Simulador da porta Or
  bool simular(const std::vector<bool3S>& in_port) override{
      if(in_port.size()>0 && in_port.size()==static_cast<size_t>(getNumInputs())){
          if(in_port[0] == bool3S::UNDEF){setOutput(bool3S::UNDEF); return false;}
          bool3S result = in_port[0];
          for(size_t i=1; i<in_port.size(); ++i){
              if(in_port[i]==bool3S::UNDEF){setOutput(bool3S::UNDEF);return false;}
              if(in_port[i]==bool3S::TRUE){result = bool3S::TRUE; break;}
          }
          setOutput(result);
          return true;
      }
      else{
          setOutput(bool3S::UNDEF);
          return false;
      }
  }
};

/// Porta NOR

class PortaNOR: public Porta
{
public:
  // PortaNOR nao tem construtor default: sempre deve ser informado o num de entradas
  PortaNOR() = delete;
  // Construtor especifico (recebe como parametro o numero de entradas da porta)
  // Se o parametro for invalido, faz Nin_port=0
  PortaNOR(int NI): Porta(NI)
  {
    if (NI<2) Nin_port=0;
  }
  // DEMAIS FUNCOES DA PORTA
  //Clonagem da porta NOr
  ptr_Porta clone() const override{
      return new PortaNOR(*this);
  }
  //Retorno do nome da porta
  std::string getName() const override{
      return "NO";
  }
  //Simulador da porta NOr
  bool simular(const std::vector<bool3S>& in_port) override{
      if(in_port.size()>0 && in_port.size()==static_cast<size_t>(getNumInputs())){
          PortaOR pOr(in_port.size());
          if(pOr.simular(in_port)){
              bool3S orResult = pOr.getOutput();
              bool3S result = (orResult == bool3S::TRUE)? bool3S::FALSE : bool3S::TRUE;
              setOutput(result);
              return true;
          }else{
              setOutput(bool3S::UNDEF);
              return false;
          }
      }
      else{
          setOutput(bool3S::UNDEF);
          return false;
      }
  }
};

/// Porta XOR

class PortaXOR: public Porta
{
public:
  // PortaXOR nao tem construtor default: sempre deve ser informado o num de entradas
  PortaXOR() = delete;
  // Construtor especifico (recebe como parametro o numero de entradas da porta)
  // Se o parametro for invalido, faz Nin_port=0
  PortaXOR(int NI): Porta(NI)
  {
    if (NI<2) Nin_port=0;
  }
  // DEMAIS FUNCOES DA PORTA
  //Clonagem da porta Xor
  ptr_Porta clone() const override{
      return new PortaXOR(*this);
  }
  //Retorno do nome da porta
  std::string getName() const override{
      return "XO";
  }
  //Simulador da porta Xor
  bool simular(const std::vector<bool3S>& in_port) override{
      if(in_port.size()>0 && in_port.size()==static_cast<size_t>(getNumInputs())){
          if(in_port[0] == bool3S::UNDEF){setOutput(bool3S::UNDEF); return false;}
          bool3S result = in_port[0];
          int TCounter = (result==bool3S::TRUE)? 1:0;
          for(size_t i=1; i<in_port.size(); ++i){
              if(in_port[i]==bool3S::UNDEF){setOutput(bool3S::UNDEF);return false;}
              if(in_port[i]==bool3S::TRUE){TCounter++;}
          }
          result = (TCounter%2==1)? bool3S::TRUE : bool3S::FALSE;
          setOutput(result);
          return true;
      }
      else{
          setOutput(bool3S::UNDEF);
          return false;
      }
  }
};

/// Porta NXOR

class PortaNXOR: public Porta
{
public:
  // PortaNXOR nao tem construtor default: sempre deve ser informado o num de entradas
  PortaNXOR() = delete;
  // Construtor especifico (recebe como parametro o numero de entradas da porta)
  // Se o parametro for invalido, faz Nin_port=0
  PortaNXOR(int NI): Porta(NI)
  {
    if (NI<2) Nin_port=0;
  }
  // DEMAIS FUNCOES DA PORTA
  //Clonagem da porta NXor
  ptr_Porta clone() const override{
      return new PortaNXOR(*this);
  }
  //Retorno do nome da porta
  std::string getName() const override{
      return "NX";
  }
  //Simulador da porta NXor
  bool simular(const std::vector<bool3S>& in_port) override{
      if(in_port.size()>0 && in_port.size()==static_cast<size_t>(getNumInputs())){
          PortaXOR pXor(in_port.size());
          if(pXor.simular(in_port)){
              bool3S xorResult = pXor.getOutput();
              bool3S result = (xorResult == bool3S::TRUE)? bool3S::FALSE : bool3S::TRUE;
              setOutput(result);
              return true;
          }else{
              setOutput(bool3S::UNDEF);
              return false;
          }
      }
      else{
          setOutput(bool3S::UNDEF);
          return false;
      }
  }
};
