#ifndef _IMGMESSAGE_H_
#define _IMGMESSAGE_H_

#ifdef WIN32
#pragma warning(disable: 4786)
#endif

#ifndef WIN32
#include <sys/time.h>
#endif

#include "scadaorb.h"
#include "scsthread.h"
#include "scsimgmodule.h"

typedef void (*ImgMessageAnswerCallback)(CORBA::Request *fromRequest, CORBA::Request *toRequest);
class MessageInfo;

class IMGBIN_API ImgMessage {

public:

  enum SendingType {
    Sync = 0,                // Two Way operation                (ScsStatusIdl expected)
    SyncVoid,            // Two way operation returning void (no return value)
    OneWay               // OneWay operation                 (no return value)
  };

  ImgMessage();
  ImgMessage(const char* interfaceName,
	     const char* operationName,
	     SendingType sendingType,
	     const ScsMessageTag& tag,
	     ImgMessageAnswerCallback callback,
	     CORBA::NVList_ptr     serverNVList,
	     CORBA::NamedValue_ptr serverNVResult,
	     CORBA::NVList_ptr     imgNVList,
	     CORBA::NamedValue_ptr imgNVResult,
	     CORBA::Request_ptr    replyRequest,
	     CORBA::ULong          timeout,
	     ScsImgModule*         module);
                   
  ~ImgMessage();

  void sendToServer();
  void sendToStandby();
        
  void answer();
  void answerAdd(ImgMessage *msg);
  void answerAdd(CORBA::Request_ptr reply);
  void answerAgain(ImgMessage *msg);
  void answerAgain(CORBA::Request_ptr reply);

  void answerFailed();
    
  int hasStandbyArgs() const { return !CORBA::is_nil(_imgNVList); } 
  int isCompleted(void); 
  bool canBeMemorized(void) const { return _canBeMemorized; }
  void setDontMemorized(void) { _canBeMemorized = false; }

  ScsMessageTag *getTag() const;

  // Returns whether current message is a 'syncWakeUp' message
  bool isSyncWakeUpMsg(void) const { return _isSyncWakeUp; }

  // Returns whether current message is a 'foregroundSnapshot' message
  bool isForegroundSnapshotMsg(void) const { return _isForegroundSnapshot; }

  // Returns whether current message has a dummy tag.
  int isDummyTag(void) const { return (_emissionTime == 0); }

  const char *      getEmissionEnv()      const { return _emissionEnv; }
  unsigned short         getNbPhysEnvRunning() const { return _nbPhysEnvRunning; }

  const timeval & getOnlineTime() const;
  void setOnlineTime(const ScsTimeValIdl& t);
  void updateStandbyTime(const timeval &currentTime);

  // Returns true if current and toTest have the same Implementation String
  int indexOfReply(CORBA::Request_ptr toTest);

  const char *asString();
  const char *operationName() const { return _operationName; };
  void printOn(SCS_SL_STD(ostream) &) const;

  friend SCS_SL_STD(ostream)& operator<<(SCS_SL_STD(ostream) &, ImgMessage&);
  friend class ImgMessageTester; 

  // creation of imgRequest if ImgMessage not created in a ScsImgModule
  // (see updateStandbyTime in inputMgr_i.cpp)
  int createImgRequest(CORBA::Object_ptr targetImg);

  // Returns the number of answers to be sent 
  // 1 by default
  const unsigned long & getNbAnswers(void) const { return _nbAnswer; }

  // Returns the sending type 
  const SendingType & getSendingType(void) const { return _sendingType; }

  CORBA::Request_ptr getReplyRequest(const int & indexReply) { return _replyRequests[indexReply]; }

  /**
   * The message kind info read acessor.
   *
   * @return The message kind info or null for special messages.
   */
  const MessageInfo* getKindInfo() const { return _info; }
  
private:

  int createServerRequest();
  int createImgRequest();
  CORBA::Request_ptr createReplyRequest(CORBA::Request_ptr reply, CORBA::NVList_ptr args);
  void sendReplyRequest(CORBA::Request_ptr reply);

  /////// Arguments ///////
        
  // global parameters
  const char *         _operationName;
  const SendingType    _sendingType;

  // request to local server
  CORBA::NVList_ptr     _serverNVList;
  CORBA::NamedValue_ptr _serverNVResult;
  CORBA::Request_ptr    _serverRequest;

  // request to remote inputMgr
  CORBA::NVList_ptr     _imgNVList;
  CORBA::NamedValue_ptr _imgNVResult;
  CORBA::Request_ptr    _imgRequest;

  // request to reply object
  CORBA::Request_ptr*   _replyRequests;

  // callback for transfer of result and out parameters in replyRequest        
  ImgMessageAnswerCallback _callback;

  // tag of the message
  char *                _emissionEnv;
  char *                _emissionName;
  const CORBA::ULong    _emissionPid;
  const CORBA::ULong    _emissionTime;
  const unsigned long   _emissionIndex;
  const unsigned short  _nbPhysEnvRunning;

  // module which has created the message
  // (needed to get destination and remote imgModule 
  // if not available at creation of message)
  ScsImgModule* _module;

  // if message is dispatched
  bool _dispatched;
        
  // time of online inputMgr
  timeval _onlineTime;

  // buffer for copying message as string
  char* _buffer;
        
  // Lock for access to reply requests
  ScsLock _answerCritical;

  // Can be memorized (more than one nbPhysEnv
  // and not on the current environment)
  bool _canBeMemorized;

  // Indicates whether this message is a 'syncWakeUp' msg
  bool _isSyncWakeUp;

  // Indicates whether this message is a 'foregroundSnapshot' msg
  bool _isForegroundSnapshot;

  unsigned long _nbAnswer;

  unsigned short _nbAnswersSent;

  // Timeout to apply on the server for this request.
  unsigned int _timeout;

  /**
   * The message kind info or null for special messages.
   */
  MessageInfo* _info;
};

#endif
