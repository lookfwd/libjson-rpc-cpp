/**
 * THIS FILE IS GENERATED BY jsonrpcstub, DO NOT CHANGE IT!!!!!
 */

#ifndef _ABSTRACTMYSTUBSERVER_H_
#define _ABSTRACTMYSTUBSERVER_H_

#include <jsonrpc/rpc.h>

class AbstractMyStubServer : public jsonrpc::AbstractServer<AbstractMyStubServer>
{
    public:
        AbstractMyStubServer(jsonrpc::AbstractServerConnector* conn) :
            jsonrpc::AbstractServer<AbstractMyStubServer>(conn)
        {
            this->bindAndAddNotification(new jsonrpc::Procedure("notifyServer",  NULL), &AbstractMyStubServer::notifyServerI);
            this->bindAndAddMethod(new jsonrpc::Procedure("sayHello",jsonrpc::JSON_STRING,"name",jsonrpc::JSON_STRING, NULL), &AbstractMyStubServer::sayHelloI);

        }
        
        inline virtual void notifyServerI(const Json::Value& request) 
        {
            this->notifyServer();
        }

        inline virtual void sayHelloI(const Json::Value& request, Json::Value& response) 
        {
            response = this->sayHello(request["name"].asString());
        }


        virtual void notifyServer() = 0;
        virtual std::string sayHello(const std::string& name) = 0;

};
#endif //_ABSTRACTMYSTUBSERVER_H_