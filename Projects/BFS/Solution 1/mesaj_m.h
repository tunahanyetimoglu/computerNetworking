//
// Generated file, do not edit! Created by nedtool 5.4 from mesaj.msg.
//

#if defined(__clang__)
#  pragma clang diagnostic ignored "-Wreserved-id-macro"
#endif
#ifndef __MESAJ_M_H
#define __MESAJ_M_H

#include <omnetpp.h>

// nedtool version check
#define MSGC_VERSION 0x0504
#if (MSGC_VERSION!=OMNETPP_VERSION)
#    error Version mismatch! Probably this file was generated by an earlier version of nedtool: 'make clean' should help.
#endif



/**
 * Class generated from <tt>mesaj.msg:17</tt> by nedtool.
 * <pre>
 * packet LayerMSG
 * {
 *     int type = 0;  // 0 layer 1 ack -1 reject
 *     double cost = 0;              // default olarak cost = 0 ;
 * }
 * </pre>
 */
class LayerMSG : public ::omnetpp::cPacket
{
  protected:
    int type;
    double cost;

  private:
    void copy(const LayerMSG& other);

  protected:
    // protected and unimplemented operator==(), to prevent accidental usage
    bool operator==(const LayerMSG&);

  public:
    LayerMSG(const char *name=nullptr, short kind=0);
    LayerMSG(const LayerMSG& other);
    virtual ~LayerMSG();
    LayerMSG& operator=(const LayerMSG& other);
    virtual LayerMSG *dup() const override {return new LayerMSG(*this);}
    virtual void parsimPack(omnetpp::cCommBuffer *b) const override;
    virtual void parsimUnpack(omnetpp::cCommBuffer *b) override;

    // field getter/setter methods
    virtual int getType() const;
    virtual void setType(int type);
    virtual double getCost() const;
    virtual void setCost(double cost);
};

inline void doParsimPacking(omnetpp::cCommBuffer *b, const LayerMSG& obj) {obj.parsimPack(b);}
inline void doParsimUnpacking(omnetpp::cCommBuffer *b, LayerMSG& obj) {obj.parsimUnpack(b);}


#endif // ifndef __MESAJ_M_H

