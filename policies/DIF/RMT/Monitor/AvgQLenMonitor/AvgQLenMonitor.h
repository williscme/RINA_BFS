//
// The MIT License (MIT)
//
// Copyright (c) 2014-2016 Brno University of Technology, PRISTINE project
//
// Permission is hereby granted, free of charge, to any person obtaining a copy
// of this software and associated documentation files (the "Software"), to deal
// in the Software without restriction, including without limitation the rights
// to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
// copies of the Software, and to permit persons to whom the Software is
// furnished to do so, subject to the following conditions:
//
// The above copyright notice and this permission notice shall be included in
// all copies or substantial portions of the Software.
//
// THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
// IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
// FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
// AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
// LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
// OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN
// THE SOFTWARE.

#ifndef AvgQLenMonitor_H_
#define AvgQLenMonitor_H_

#include "DIF/RMT/Monitor/RMTQMonitorBase.h"

typedef std::map<RMTQueue*, double> AvgQLenParamMap;

class AvgQLenMonitor : public RMTQMonitorBase
{
  friend class REDDropper;

  public:
    virtual void prePDUInsertion(RMTQueue* queue);
    virtual void postPDUInsertion(RMTQueue* queue);
    virtual void postQueueCreation(RMTQueue* queue);
    virtual void preQueueRemoval(RMTQueue* queue);
    virtual void postPDURelease(RMTQueue* queue);

    const AvgQLenParamMap& getAvgLengths() const {
        return qAvgLengths;
    }

    void setAvgLengths(const AvgQLenParamMap& avgLengths) {
        qAvgLengths = avgLengths;
    }

    const AvgQLenParamMap& getCounters() const {
        return qCounters;
    }

    void setCounters(const AvgQLenParamMap& counters) {
        qCounters = counters;
    }

    const AvgQLenParamMap& getWeights() const {
        return qWeights;
    }

    void setWeights(const AvgQLenParamMap& weights) {
        qWeights = weights;
    }

    const simtime_t getPrevRegenCycleTimestamp() {
        return prevRegenCycleTimestamp;
    }

    void setPrevRegenCycleTimestamp(simtime_t timestamp) {
        prevRegenCycleTimestamp = timestamp;
    }

    const simtime_t getCurrentRegenCycleTimestamp() {
        return currentRegenCycleTimestamp;
    }

    void setCurrentRegenCycleTimestamp(simtime_t timestamp) {
        currentRegenCycleTimestamp = timestamp;
    }

    const int getPrevRegenCycleQLen() {
        return prevRegenCycleQLen;
    }

    void setPrevRegenCycleQLen(int qLength) {
        prevRegenCycleQLen = qLength;
    }

    const int getCurrentRegenCycleQLen() {
        return currentRegenCycleQLen;
    }

    void setCurrentRegenCycleQLen(int qLength) {
        currentRegenCycleQLen = qLength;
    }

  public:
    AvgQLenParamMap qAvgLengths;
    AvgQLenParamMap qWeights;
    AvgQLenParamMap qCounters;

    // Regeneration Cycle = time in between queue length being greater than or equal to one (Raj Jain)
    // Keeps track of previous/current regeneration cycle's timestamp
    simtime_t prevRegenCycleTimestamp;
    simtime_t currentRegenCycleTimestamp;
    double prevRegenCycleQLen;
    double currentRegenCycleQLen;
};

#endif /* AvgQLenMonitor_H_ */
