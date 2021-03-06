#include "MainHeader.h"

class FST : public cSimpleModule
{
private:
    std::vector<std::string> children;
protected:
    virtual Message *generateMessage(const char *name,short int kind);
    virtual void initialize() override;
    virtual void handleMessage(cMessage *msg) override;

};

int gateIndex,gateId,messageCode;

Define_Module(FST);

void FST::initialize()
{
    if (strcmp(ROOT,getName()) == 0) {
        par("hasParent") = true;
        Message *msg = generateMessage("Probe", 2);
        scheduleAt(0.0, msg);
    }
}
void FST::handleMessage(cMessage *msg)
{
    Message *mmsg = check_and_cast<Message *>(msg);
    messageCode = mmsg->getMessageCode();
    if(messageCode == 0){
        cDisplayString& arrivalDispStr = gate(GATENAME, mmsg->getArrivalGate()->getIndex())->getDisplayString();
        arrivalDispStr.parse("ls=,0");
    }
    else{
         switch(messageCode){
             case (PROBECODE):
                    gateId =  msg->getArrivalGateId();
                    if( gateId != -1){
                        gateIndex = msg->getArrivalGate()->getIndex();
                        if(par("hasParent").boolValue() == false){
                            par("hasParent") = true;
                            send(generateMessage("Ack", 1), GATENAME, gateIndex);
                            cDisplayString& arrivalDispStr = gate(GATENAME, gateIndex)->getDisplayString();
                            arrivalDispStr.parse("ls=green,3");

                            for(int i = 0; i < this->gateCount() / 2; i++){
                                if(msg->arrivedOn(GATENAME_i, i)){continue;}
                                send(generateMessage("Probe", 2), GATENAME, i);
                            }
                        }else{
                            send(generateMessage("Reject", 0), GATENAME, gateIndex);
                        }
                    }else{
                        for(int i = 0; i < this->gateCount() / 2; i++){
                            if(msg->arrivedOn(GATENAME_i, i)){continue;}
                            send(generateMessage("Probe", 2),GATENAME, i);
                        }
                    }
                    break;
             case (ACKCODE):
                    children.push_back(msg->getArrivalGate()->getPreviousGate()->getOwner()->getName());
                    cDisplayString& arrivalDispStr = gate(GATENAME, msg->getArrivalGate()->getIndex())->getDisplayString();
                    arrivalDispStr.parse("ls=blue,5");

                    EV << getName() << "'s childs: ";
                    for(int i = 0; i < children.size(); i++){
                        EV << children.at(i) << " , ";
                    }
                    EV << endl;
                    break;
         }
    }
    delete mmsg;
}

Message *FST::generateMessage(const char *name,short int kind)
{
    Message *msg = new Message(name,kind);
    if(strcmp(name, "Probe") == 0){
        msg->setMessageCode(2);
    }else if(strcmp(name,"Ack") == 0){
        msg->setMessageCode(1);
    }else if(strcmp(name,"Reject") == 0){
        msg->setMessageCode(0);
    }
    return msg;
}

