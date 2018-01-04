//
// JSValue.h
//
// LiquidPlayer project
// https://github.com/LiquidPlayer
//
// Created by Eric Lange
//
/*
 Copyright (c) 2016 - 2018 Eric Lange. All rights reserved.

 Redistribution and use in source and binary forms, with or without
 modification, are permitted provided that the following conditions are met:

 - Redistributions of source code must retain the above copyright notice, this
 list of conditions and the following disclaimer.

 - Redistributions in binary form must reproduce the above copyright notice,
 this list of conditions and the following disclaimer in the documentation
 and/or other materials provided with the distribution.

 THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS"
 AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE
 IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE
 DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT HOLDER OR CONTRIBUTORS BE LIABLE
 FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL
 DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR
 SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER
 CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY,
 OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE
 OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
*/
#ifndef LIQUIDCORE_JSVALUE_H
#define LIQUIDCORE_JSVALUE_H

#include "Common/JSContext.h"

using namespace v8;

class JSValue : public std::enable_shared_from_this<JSValue>, public ManagedObject {
public:
    JSValue(std::shared_ptr<JSContext> context, Local<v8::Value> val);
    JSValue();
    virtual ~JSValue();

    virtual Local<v8::Value> Value();
    virtual Isolate* isolate();
    virtual std::shared_ptr<ContextGroup> Group();
    virtual std::shared_ptr<JSContext> Context();
    virtual void Dispose();

    static std::shared_ptr<JSValue> New(std::shared_ptr<JSContext> context, Local<v8::Value> val);

protected:
    Persistent<v8::Value, CopyablePersistentTraits<v8::Value>> m_value;
    std::shared_ptr<JSContext> m_context;
    bool m_isUndefined;
    bool m_isNull;
    bool m_wrapped;

private:
    bool m_isDefunct;
};

#endif //LIQUIDCORE_JSVALUE_H