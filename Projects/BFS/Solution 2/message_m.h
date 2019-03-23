//
// Generated file, do not edit! Created by nedtool 5.4 from message.msg.
//

#if defined(__clang__)
#  pragma clang diagnostic ignored "-Wreserved-id-macro"
#endif
#ifndef __MESSAGE_M_H
#define __MESSAGE_M_H

#include <omnetpp.h>

// nedtool version check
#define MSGC_VERSION 0x0504
#if (MSGC_VERSION!=OMNETPP_VERSION)
#    error Version mismatch! Probably this file was generated by an earlier version of nedtool: 'make clean' should help.
#endif



/**
 * Class generated from <tt>message.msg:17</tt> by nedtool.
 * <pre>
 * packet layerM
 * {
 *     double delay = 0;
 * }
 * </pre>
 */
class layerM : public ::omnetpp::cPacket
{
  protected:
    double delay;

  private:
    void copy(const layerM& other);

  protected:
    // protected and unimplemented operator==(), to prevent accidental usage
    bool operator==(const layerM&);

  public:
    layerM(const char *name=nullptr, short kind=0);
    layerM(const layerM& other);
    virtual ~layerM();
    layerM& operator=(const layerM& other);
    virtual layerM *dup() const override {return new layerM(*this);}
    virtual void parsimPack(omnetpp::cCommBuffer *b) const override;
    virtual void parsimUnpack(omnetpp::cCommBuffer *b) override;

    // field getter/setter methods
    virtual double getDelay() const;
    virtual void setDelay(double delay);
};

inline void doParsimPacking(omnetpp::cCommBuffer *b, const layerM& obj) {obj.parsimPack(b);}
inline void doParsimUnpacking(omnetpp::cCommBuffer *b, layerM& obj) {obj.parsimUnpack(b);}


#endif // ifndef __MESSAGE_M_H

