#include "porta.h"

///
/// AS PORTAS
///

/// Porta NOT
    ptr_Porta PortaNOT::clone() const{
        return new PortaNOT(*this);
    }
    //Retorno do nome da porta
    std::string PortaNOT::getName() const{
        return "NT";
    }
    //Simulador da porta Not
    bool PortaNOT::simular(const std::vector<bool3S>& in_port){
        if(in_port.size()==1){
            setOutput(~in_port[0]);
            return true;
        }
        else{
            setOutput(bool3S::UNDEF);
            return false;
        }
    }

/// Porta AND
    //Clonagem da porta And
    ptr_Porta PortaAND::clone() const{
        return new PortaAND(*this);
    }
    //Retorno do nome da porta
    std::string PortaAND::getName() const{
        return "AN";
    }
    //Simulador da porta And
    bool PortaAND::simular(const std::vector<bool3S>& in_port){
        if(in_port.size()>0 && in_port.size()==static_cast<size_t>(getNumInputs())){
            bool3S result = in_port[0];
            for (int i = 1; i < getNumInputs(); ++i){
                result &= in_port[i];
            }
            setOutput(result);
            return true;
        }
        else{
            setOutput(bool3S::UNDEF);
            return false;
        }
    }

/// Porta NAND
    ptr_Porta PortaNAND::clone() const{
        return new PortaNAND(*this);
    }
    //Retorno do nome da porta
    std::string PortaNAND::getName() const{
        return "NA";
    }
    //Simulador da porta NAnd
    bool PortaNAND::simular(const std::vector<bool3S>& in_port){
        if(in_port.size()>0 && in_port.size()==static_cast<size_t>(getNumInputs())){
            bool3S result = in_port[0];
            for (int i = 1; i < getNumInputs(); ++i){
                result &= in_port[i];
            }
            setOutput(~result);
            return true;
        }
        else{
            setOutput(bool3S::UNDEF);
            return false;
        }
    }

/// Porta OR
    //Clonagem da porta Or
    ptr_Porta PortaOR::clone() const{
        return new PortaOR(*this);
    }
    //Retorno do nome da porta
    std::string PortaOR::getName() const{
        return "OR";
    }
    //Simulador da porta Or
    bool PortaOR::simular(const std::vector<bool3S>& in_port){
        if(in_port.size()>0 && in_port.size()==static_cast<size_t>(getNumInputs())){
            bool3S result = in_port[0];
            for (int i = 1; i < getNumInputs(); ++i){
                result |= in_port[i];
            }
            setOutput(result);
            return true;
        }
        else{
            setOutput(bool3S::UNDEF);
            return false;
        }
    }

/// Porta NOR
    //Clonagem da porta NOr
    ptr_Porta PortaNOR::clone() const {
        return new PortaNOR(*this);
    }
    //Retorno do nome da porta
    std::string PortaNOR::getName() const{
        return "NO";
    }
    //Simulador da porta NOr
    bool PortaNOR::simular(const std::vector<bool3S>& in_port){
        if(in_port.size()>0 && in_port.size()==static_cast<size_t>(getNumInputs())){
            bool3S result = in_port[0];
            for (int i = 1; i < getNumInputs(); ++i){
                result |= in_port[i];
            }
            setOutput(~result);
            return true;
        }
        else{
            setOutput(bool3S::UNDEF);
            return false;
        }
    }
/// Porta XOR
    //Clonagem da porta Xor
    ptr_Porta PortaXOR::clone() const{
        return new PortaXOR(*this);
    }
    //Retorno do nome da porta
    std::string PortaXOR::getName() const{
        return "XO";
    }
    //Simulador da porta Xor
    bool PortaXOR::simular(const std::vector<bool3S>& in_port){
        if(in_port.size()>0 && in_port.size()==static_cast<size_t>(getNumInputs())){
            bool3S result = in_port[0];
            for (int i = 1; i < getNumInputs(); ++i){
                result ^= in_port[i];
            }
            setOutput(result);
            return true;
        }
        else{
            setOutput(bool3S::UNDEF);
            return false;
        }
    }

/// Porta NXOR
    //Clonagem da porta NXor
    ptr_Porta PortaNXOR::clone() const{
        return new PortaNXOR(*this);
    }
    //Retorno do nome da porta
    std::string PortaNXOR::getName() const{
        return "NX";
    }
    //Simulador da porta NXor
    bool PortaNXOR::simular(const std::vector<bool3S>& in_port){
        if(in_port.size()>0 && in_port.size()==static_cast<size_t>(getNumInputs())){
            bool3S result = in_port[0];
            for (int i = 1; i < getNumInputs(); ++i){
                result ^= in_port[i];
            }
            setOutput(~result);
            return true;
        }
        else{
            setOutput(bool3S::UNDEF);
            return false;
        }
    }
