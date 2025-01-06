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
            int falseCont = 0;
            for(size_t i=0; i<in_port.size(); ++i){if(in_port[i]==bool3S::FALSE){++falseCont;}};
            if(falseCont){setOutput(bool3S::FALSE); return true;};
            bool3S result = in_port[0];
            for(size_t i=1; i<in_port.size(); ++i){
                if(in_port[i]==bool3S::UNDEF){setOutput(bool3S::UNDEF); return true;}
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
            PortaAND pAnd(in_port.size());
            if(pAnd.simular(in_port)){
                bool3S andResult = pAnd.getOutput();
                if(andResult==bool3S::UNDEF){setOutput(bool3S::UNDEF); return true;}
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
            int trueCont = 0;
            for(size_t i=0; i<in_port.size(); ++i){if(in_port[i]==bool3S::TRUE){++trueCont;}};
            if(trueCont){setOutput(bool3S::TRUE); return true;};
            bool3S result = in_port[0];
            for(size_t i=1; i<in_port.size(); ++i){
                if(in_port[i]==bool3S::UNDEF){setOutput(bool3S::UNDEF); return true;}
                if(in_port[i]==bool3S::TRUE){result=bool3S::TRUE; break;}
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
            PortaOR pOr(in_port.size());
            if(pOr.simular(in_port)){
                bool3S orResult = pOr.getOutput();
                if(orResult==bool3S::UNDEF){setOutput(bool3S::UNDEF); return true;}
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
            if(in_port[0] == bool3S::UNDEF){setOutput(bool3S::UNDEF); return true;}
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
            PortaXOR pXor(in_port.size());
            if(pXor.simular(in_port)){
                bool3S xorResult = pXor.getOutput();
                if(xorResult==bool3S::UNDEF){setOutput(bool3S::UNDEF); return true;}
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
