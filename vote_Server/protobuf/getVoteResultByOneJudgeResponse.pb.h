// Generated by the protocol buffer compiler.  DO NOT EDIT!
// source: getVoteResultByOneJudgeResponse.proto

#ifndef PROTOBUF_INCLUDED_getVoteResultByOneJudgeResponse_2eproto
#define PROTOBUF_INCLUDED_getVoteResultByOneJudgeResponse_2eproto

#include <string>

#include <google/protobuf/stubs/common.h>

#if GOOGLE_PROTOBUF_VERSION < 3006001
#error This file was generated by a newer version of protoc which is
#error incompatible with your Protocol Buffer headers.  Please update
#error your headers.
#endif
#if 3006001 < GOOGLE_PROTOBUF_MIN_PROTOC_VERSION
#error This file was generated by an older version of protoc which is
#error incompatible with your Protocol Buffer headers.  Please
#error regenerate this file with a newer version of protoc.
#endif

#include <google/protobuf/io/coded_stream.h>
#include <google/protobuf/arena.h>
#include <google/protobuf/arenastring.h>
#include <google/protobuf/generated_message_table_driven.h>
#include <google/protobuf/generated_message_util.h>
#include <google/protobuf/inlined_string_field.h>
#include <google/protobuf/metadata.h>
#include <google/protobuf/message.h>
#include <google/protobuf/repeated_field.h>  // IWYU pragma: export
#include <google/protobuf/extension_set.h>  // IWYU pragma: export
#include <google/protobuf/unknown_field_set.h>
// @@protoc_insertion_point(includes)
#define PROTOBUF_INTERNAL_EXPORT_protobuf_getVoteResultByOneJudgeResponse_2eproto 

namespace protobuf_getVoteResultByOneJudgeResponse_2eproto {
// Internal implementation detail -- do not use these members.
struct TableStruct {
  static const ::google::protobuf::internal::ParseTableField entries[];
  static const ::google::protobuf::internal::AuxillaryParseTableField aux[];
  static const ::google::protobuf::internal::ParseTable schema[2];
  static const ::google::protobuf::internal::FieldMetadata field_metadata[];
  static const ::google::protobuf::internal::SerializationTable serialization_table[];
  static const ::google::protobuf::uint32 offsets[];
};
void AddDescriptors();
}  // namespace protobuf_getVoteResultByOneJudgeResponse_2eproto
namespace protoMsg {
class GetVoteResultByOneJudgeResponse;
class GetVoteResultByOneJudgeResponseDefaultTypeInternal;
extern GetVoteResultByOneJudgeResponseDefaultTypeInternal _GetVoteResultByOneJudgeResponse_default_instance_;
class GetVoteResultByOneJudgeResponse_Vote;
class GetVoteResultByOneJudgeResponse_VoteDefaultTypeInternal;
extern GetVoteResultByOneJudgeResponse_VoteDefaultTypeInternal _GetVoteResultByOneJudgeResponse_Vote_default_instance_;
}  // namespace protoMsg
namespace google {
namespace protobuf {
template<> ::protoMsg::GetVoteResultByOneJudgeResponse* Arena::CreateMaybeMessage<::protoMsg::GetVoteResultByOneJudgeResponse>(Arena*);
template<> ::protoMsg::GetVoteResultByOneJudgeResponse_Vote* Arena::CreateMaybeMessage<::protoMsg::GetVoteResultByOneJudgeResponse_Vote>(Arena*);
}  // namespace protobuf
}  // namespace google
namespace protoMsg {

// ===================================================================

class GetVoteResultByOneJudgeResponse_Vote : public ::google::protobuf::Message /* @@protoc_insertion_point(class_definition:protoMsg.GetVoteResultByOneJudgeResponse.Vote) */ {
 public:
  GetVoteResultByOneJudgeResponse_Vote();
  virtual ~GetVoteResultByOneJudgeResponse_Vote();

  GetVoteResultByOneJudgeResponse_Vote(const GetVoteResultByOneJudgeResponse_Vote& from);

  inline GetVoteResultByOneJudgeResponse_Vote& operator=(const GetVoteResultByOneJudgeResponse_Vote& from) {
    CopyFrom(from);
    return *this;
  }
  #if LANG_CXX11
  GetVoteResultByOneJudgeResponse_Vote(GetVoteResultByOneJudgeResponse_Vote&& from) noexcept
    : GetVoteResultByOneJudgeResponse_Vote() {
    *this = ::std::move(from);
  }

  inline GetVoteResultByOneJudgeResponse_Vote& operator=(GetVoteResultByOneJudgeResponse_Vote&& from) noexcept {
    if (GetArenaNoVirtual() == from.GetArenaNoVirtual()) {
      if (this != &from) InternalSwap(&from);
    } else {
      CopyFrom(from);
    }
    return *this;
  }
  #endif
  static const ::google::protobuf::Descriptor* descriptor();
  static const GetVoteResultByOneJudgeResponse_Vote& default_instance();

  static void InitAsDefaultInstance();  // FOR INTERNAL USE ONLY
  static inline const GetVoteResultByOneJudgeResponse_Vote* internal_default_instance() {
    return reinterpret_cast<const GetVoteResultByOneJudgeResponse_Vote*>(
               &_GetVoteResultByOneJudgeResponse_Vote_default_instance_);
  }
  static constexpr int kIndexInFileMessages =
    0;

  void Swap(GetVoteResultByOneJudgeResponse_Vote* other);
  friend void swap(GetVoteResultByOneJudgeResponse_Vote& a, GetVoteResultByOneJudgeResponse_Vote& b) {
    a.Swap(&b);
  }

  // implements Message ----------------------------------------------

  inline GetVoteResultByOneJudgeResponse_Vote* New() const final {
    return CreateMaybeMessage<GetVoteResultByOneJudgeResponse_Vote>(NULL);
  }

  GetVoteResultByOneJudgeResponse_Vote* New(::google::protobuf::Arena* arena) const final {
    return CreateMaybeMessage<GetVoteResultByOneJudgeResponse_Vote>(arena);
  }
  void CopyFrom(const ::google::protobuf::Message& from) final;
  void MergeFrom(const ::google::protobuf::Message& from) final;
  void CopyFrom(const GetVoteResultByOneJudgeResponse_Vote& from);
  void MergeFrom(const GetVoteResultByOneJudgeResponse_Vote& from);
  void Clear() final;
  bool IsInitialized() const final;

  size_t ByteSizeLong() const final;
  bool MergePartialFromCodedStream(
      ::google::protobuf::io::CodedInputStream* input) final;
  void SerializeWithCachedSizes(
      ::google::protobuf::io::CodedOutputStream* output) const final;
  ::google::protobuf::uint8* InternalSerializeWithCachedSizesToArray(
      bool deterministic, ::google::protobuf::uint8* target) const final;
  int GetCachedSize() const final { return _cached_size_.Get(); }

  private:
  void SharedCtor();
  void SharedDtor();
  void SetCachedSize(int size) const final;
  void InternalSwap(GetVoteResultByOneJudgeResponse_Vote* other);
  private:
  inline ::google::protobuf::Arena* GetArenaNoVirtual() const {
    return NULL;
  }
  inline void* MaybeArenaPtr() const {
    return NULL;
  }
  public:

  ::google::protobuf::Metadata GetMetadata() const final;

  // nested types ----------------------------------------------------

  // accessors -------------------------------------------------------

  // string voteName = 1;
  void clear_votename();
  static const int kVoteNameFieldNumber = 1;
  const ::std::string& votename() const;
  void set_votename(const ::std::string& value);
  #if LANG_CXX11
  void set_votename(::std::string&& value);
  #endif
  void set_votename(const char* value);
  void set_votename(const char* value, size_t size);
  ::std::string* mutable_votename();
  ::std::string* release_votename();
  void set_allocated_votename(::std::string* votename);

  // string voteID = 2;
  void clear_voteid();
  static const int kVoteIDFieldNumber = 2;
  const ::std::string& voteid() const;
  void set_voteid(const ::std::string& value);
  #if LANG_CXX11
  void set_voteid(::std::string&& value);
  #endif
  void set_voteid(const char* value);
  void set_voteid(const char* value, size_t size);
  ::std::string* mutable_voteid();
  ::std::string* release_voteid();
  void set_allocated_voteid(::std::string* voteid);

  // string isValid = 3;
  void clear_isvalid();
  static const int kIsValidFieldNumber = 3;
  const ::std::string& isvalid() const;
  void set_isvalid(const ::std::string& value);
  #if LANG_CXX11
  void set_isvalid(::std::string&& value);
  #endif
  void set_isvalid(const char* value);
  void set_isvalid(const char* value, size_t size);
  ::std::string* mutable_isvalid();
  ::std::string* release_isvalid();
  void set_allocated_isvalid(::std::string* isvalid);

  // string isVoted = 4;
  void clear_isvoted();
  static const int kIsVotedFieldNumber = 4;
  const ::std::string& isvoted() const;
  void set_isvoted(const ::std::string& value);
  #if LANG_CXX11
  void set_isvoted(::std::string&& value);
  #endif
  void set_isvoted(const char* value);
  void set_isvoted(const char* value, size_t size);
  ::std::string* mutable_isvoted();
  ::std::string* release_isvoted();
  void set_allocated_isvoted(::std::string* isvoted);

  // @@protoc_insertion_point(class_scope:protoMsg.GetVoteResultByOneJudgeResponse.Vote)
 private:

  ::google::protobuf::internal::InternalMetadataWithArena _internal_metadata_;
  ::google::protobuf::internal::ArenaStringPtr votename_;
  ::google::protobuf::internal::ArenaStringPtr voteid_;
  ::google::protobuf::internal::ArenaStringPtr isvalid_;
  ::google::protobuf::internal::ArenaStringPtr isvoted_;
  mutable ::google::protobuf::internal::CachedSize _cached_size_;
  friend struct ::protobuf_getVoteResultByOneJudgeResponse_2eproto::TableStruct;
};
// -------------------------------------------------------------------

class GetVoteResultByOneJudgeResponse : public ::google::protobuf::Message /* @@protoc_insertion_point(class_definition:protoMsg.GetVoteResultByOneJudgeResponse) */ {
 public:
  GetVoteResultByOneJudgeResponse();
  virtual ~GetVoteResultByOneJudgeResponse();

  GetVoteResultByOneJudgeResponse(const GetVoteResultByOneJudgeResponse& from);

  inline GetVoteResultByOneJudgeResponse& operator=(const GetVoteResultByOneJudgeResponse& from) {
    CopyFrom(from);
    return *this;
  }
  #if LANG_CXX11
  GetVoteResultByOneJudgeResponse(GetVoteResultByOneJudgeResponse&& from) noexcept
    : GetVoteResultByOneJudgeResponse() {
    *this = ::std::move(from);
  }

  inline GetVoteResultByOneJudgeResponse& operator=(GetVoteResultByOneJudgeResponse&& from) noexcept {
    if (GetArenaNoVirtual() == from.GetArenaNoVirtual()) {
      if (this != &from) InternalSwap(&from);
    } else {
      CopyFrom(from);
    }
    return *this;
  }
  #endif
  static const ::google::protobuf::Descriptor* descriptor();
  static const GetVoteResultByOneJudgeResponse& default_instance();

  static void InitAsDefaultInstance();  // FOR INTERNAL USE ONLY
  static inline const GetVoteResultByOneJudgeResponse* internal_default_instance() {
    return reinterpret_cast<const GetVoteResultByOneJudgeResponse*>(
               &_GetVoteResultByOneJudgeResponse_default_instance_);
  }
  static constexpr int kIndexInFileMessages =
    1;

  void Swap(GetVoteResultByOneJudgeResponse* other);
  friend void swap(GetVoteResultByOneJudgeResponse& a, GetVoteResultByOneJudgeResponse& b) {
    a.Swap(&b);
  }

  // implements Message ----------------------------------------------

  inline GetVoteResultByOneJudgeResponse* New() const final {
    return CreateMaybeMessage<GetVoteResultByOneJudgeResponse>(NULL);
  }

  GetVoteResultByOneJudgeResponse* New(::google::protobuf::Arena* arena) const final {
    return CreateMaybeMessage<GetVoteResultByOneJudgeResponse>(arena);
  }
  void CopyFrom(const ::google::protobuf::Message& from) final;
  void MergeFrom(const ::google::protobuf::Message& from) final;
  void CopyFrom(const GetVoteResultByOneJudgeResponse& from);
  void MergeFrom(const GetVoteResultByOneJudgeResponse& from);
  void Clear() final;
  bool IsInitialized() const final;

  size_t ByteSizeLong() const final;
  bool MergePartialFromCodedStream(
      ::google::protobuf::io::CodedInputStream* input) final;
  void SerializeWithCachedSizes(
      ::google::protobuf::io::CodedOutputStream* output) const final;
  ::google::protobuf::uint8* InternalSerializeWithCachedSizesToArray(
      bool deterministic, ::google::protobuf::uint8* target) const final;
  int GetCachedSize() const final { return _cached_size_.Get(); }

  private:
  void SharedCtor();
  void SharedDtor();
  void SetCachedSize(int size) const final;
  void InternalSwap(GetVoteResultByOneJudgeResponse* other);
  private:
  inline ::google::protobuf::Arena* GetArenaNoVirtual() const {
    return NULL;
  }
  inline void* MaybeArenaPtr() const {
    return NULL;
  }
  public:

  ::google::protobuf::Metadata GetMetadata() const final;

  // nested types ----------------------------------------------------

  typedef GetVoteResultByOneJudgeResponse_Vote Vote;

  // accessors -------------------------------------------------------

  // repeated .protoMsg.GetVoteResultByOneJudgeResponse.Vote votes = 1;
  int votes_size() const;
  void clear_votes();
  static const int kVotesFieldNumber = 1;
  ::protoMsg::GetVoteResultByOneJudgeResponse_Vote* mutable_votes(int index);
  ::google::protobuf::RepeatedPtrField< ::protoMsg::GetVoteResultByOneJudgeResponse_Vote >*
      mutable_votes();
  const ::protoMsg::GetVoteResultByOneJudgeResponse_Vote& votes(int index) const;
  ::protoMsg::GetVoteResultByOneJudgeResponse_Vote* add_votes();
  const ::google::protobuf::RepeatedPtrField< ::protoMsg::GetVoteResultByOneJudgeResponse_Vote >&
      votes() const;

  // @@protoc_insertion_point(class_scope:protoMsg.GetVoteResultByOneJudgeResponse)
 private:

  ::google::protobuf::internal::InternalMetadataWithArena _internal_metadata_;
  ::google::protobuf::RepeatedPtrField< ::protoMsg::GetVoteResultByOneJudgeResponse_Vote > votes_;
  mutable ::google::protobuf::internal::CachedSize _cached_size_;
  friend struct ::protobuf_getVoteResultByOneJudgeResponse_2eproto::TableStruct;
};
// ===================================================================


// ===================================================================

#ifdef __GNUC__
  #pragma GCC diagnostic push
  #pragma GCC diagnostic ignored "-Wstrict-aliasing"
#endif  // __GNUC__
// GetVoteResultByOneJudgeResponse_Vote

// string voteName = 1;
inline void GetVoteResultByOneJudgeResponse_Vote::clear_votename() {
  votename_.ClearToEmptyNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited());
}
inline const ::std::string& GetVoteResultByOneJudgeResponse_Vote::votename() const {
  // @@protoc_insertion_point(field_get:protoMsg.GetVoteResultByOneJudgeResponse.Vote.voteName)
  return votename_.GetNoArena();
}
inline void GetVoteResultByOneJudgeResponse_Vote::set_votename(const ::std::string& value) {
  
  votename_.SetNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited(), value);
  // @@protoc_insertion_point(field_set:protoMsg.GetVoteResultByOneJudgeResponse.Vote.voteName)
}
#if LANG_CXX11
inline void GetVoteResultByOneJudgeResponse_Vote::set_votename(::std::string&& value) {
  
  votename_.SetNoArena(
    &::google::protobuf::internal::GetEmptyStringAlreadyInited(), ::std::move(value));
  // @@protoc_insertion_point(field_set_rvalue:protoMsg.GetVoteResultByOneJudgeResponse.Vote.voteName)
}
#endif
inline void GetVoteResultByOneJudgeResponse_Vote::set_votename(const char* value) {
  GOOGLE_DCHECK(value != NULL);
  
  votename_.SetNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited(), ::std::string(value));
  // @@protoc_insertion_point(field_set_char:protoMsg.GetVoteResultByOneJudgeResponse.Vote.voteName)
}
inline void GetVoteResultByOneJudgeResponse_Vote::set_votename(const char* value, size_t size) {
  
  votename_.SetNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited(),
      ::std::string(reinterpret_cast<const char*>(value), size));
  // @@protoc_insertion_point(field_set_pointer:protoMsg.GetVoteResultByOneJudgeResponse.Vote.voteName)
}
inline ::std::string* GetVoteResultByOneJudgeResponse_Vote::mutable_votename() {
  
  // @@protoc_insertion_point(field_mutable:protoMsg.GetVoteResultByOneJudgeResponse.Vote.voteName)
  return votename_.MutableNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited());
}
inline ::std::string* GetVoteResultByOneJudgeResponse_Vote::release_votename() {
  // @@protoc_insertion_point(field_release:protoMsg.GetVoteResultByOneJudgeResponse.Vote.voteName)
  
  return votename_.ReleaseNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited());
}
inline void GetVoteResultByOneJudgeResponse_Vote::set_allocated_votename(::std::string* votename) {
  if (votename != NULL) {
    
  } else {
    
  }
  votename_.SetAllocatedNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited(), votename);
  // @@protoc_insertion_point(field_set_allocated:protoMsg.GetVoteResultByOneJudgeResponse.Vote.voteName)
}

// string voteID = 2;
inline void GetVoteResultByOneJudgeResponse_Vote::clear_voteid() {
  voteid_.ClearToEmptyNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited());
}
inline const ::std::string& GetVoteResultByOneJudgeResponse_Vote::voteid() const {
  // @@protoc_insertion_point(field_get:protoMsg.GetVoteResultByOneJudgeResponse.Vote.voteID)
  return voteid_.GetNoArena();
}
inline void GetVoteResultByOneJudgeResponse_Vote::set_voteid(const ::std::string& value) {
  
  voteid_.SetNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited(), value);
  // @@protoc_insertion_point(field_set:protoMsg.GetVoteResultByOneJudgeResponse.Vote.voteID)
}
#if LANG_CXX11
inline void GetVoteResultByOneJudgeResponse_Vote::set_voteid(::std::string&& value) {
  
  voteid_.SetNoArena(
    &::google::protobuf::internal::GetEmptyStringAlreadyInited(), ::std::move(value));
  // @@protoc_insertion_point(field_set_rvalue:protoMsg.GetVoteResultByOneJudgeResponse.Vote.voteID)
}
#endif
inline void GetVoteResultByOneJudgeResponse_Vote::set_voteid(const char* value) {
  GOOGLE_DCHECK(value != NULL);
  
  voteid_.SetNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited(), ::std::string(value));
  // @@protoc_insertion_point(field_set_char:protoMsg.GetVoteResultByOneJudgeResponse.Vote.voteID)
}
inline void GetVoteResultByOneJudgeResponse_Vote::set_voteid(const char* value, size_t size) {
  
  voteid_.SetNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited(),
      ::std::string(reinterpret_cast<const char*>(value), size));
  // @@protoc_insertion_point(field_set_pointer:protoMsg.GetVoteResultByOneJudgeResponse.Vote.voteID)
}
inline ::std::string* GetVoteResultByOneJudgeResponse_Vote::mutable_voteid() {
  
  // @@protoc_insertion_point(field_mutable:protoMsg.GetVoteResultByOneJudgeResponse.Vote.voteID)
  return voteid_.MutableNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited());
}
inline ::std::string* GetVoteResultByOneJudgeResponse_Vote::release_voteid() {
  // @@protoc_insertion_point(field_release:protoMsg.GetVoteResultByOneJudgeResponse.Vote.voteID)
  
  return voteid_.ReleaseNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited());
}
inline void GetVoteResultByOneJudgeResponse_Vote::set_allocated_voteid(::std::string* voteid) {
  if (voteid != NULL) {
    
  } else {
    
  }
  voteid_.SetAllocatedNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited(), voteid);
  // @@protoc_insertion_point(field_set_allocated:protoMsg.GetVoteResultByOneJudgeResponse.Vote.voteID)
}

// string isValid = 3;
inline void GetVoteResultByOneJudgeResponse_Vote::clear_isvalid() {
  isvalid_.ClearToEmptyNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited());
}
inline const ::std::string& GetVoteResultByOneJudgeResponse_Vote::isvalid() const {
  // @@protoc_insertion_point(field_get:protoMsg.GetVoteResultByOneJudgeResponse.Vote.isValid)
  return isvalid_.GetNoArena();
}
inline void GetVoteResultByOneJudgeResponse_Vote::set_isvalid(const ::std::string& value) {
  
  isvalid_.SetNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited(), value);
  // @@protoc_insertion_point(field_set:protoMsg.GetVoteResultByOneJudgeResponse.Vote.isValid)
}
#if LANG_CXX11
inline void GetVoteResultByOneJudgeResponse_Vote::set_isvalid(::std::string&& value) {
  
  isvalid_.SetNoArena(
    &::google::protobuf::internal::GetEmptyStringAlreadyInited(), ::std::move(value));
  // @@protoc_insertion_point(field_set_rvalue:protoMsg.GetVoteResultByOneJudgeResponse.Vote.isValid)
}
#endif
inline void GetVoteResultByOneJudgeResponse_Vote::set_isvalid(const char* value) {
  GOOGLE_DCHECK(value != NULL);
  
  isvalid_.SetNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited(), ::std::string(value));
  // @@protoc_insertion_point(field_set_char:protoMsg.GetVoteResultByOneJudgeResponse.Vote.isValid)
}
inline void GetVoteResultByOneJudgeResponse_Vote::set_isvalid(const char* value, size_t size) {
  
  isvalid_.SetNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited(),
      ::std::string(reinterpret_cast<const char*>(value), size));
  // @@protoc_insertion_point(field_set_pointer:protoMsg.GetVoteResultByOneJudgeResponse.Vote.isValid)
}
inline ::std::string* GetVoteResultByOneJudgeResponse_Vote::mutable_isvalid() {
  
  // @@protoc_insertion_point(field_mutable:protoMsg.GetVoteResultByOneJudgeResponse.Vote.isValid)
  return isvalid_.MutableNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited());
}
inline ::std::string* GetVoteResultByOneJudgeResponse_Vote::release_isvalid() {
  // @@protoc_insertion_point(field_release:protoMsg.GetVoteResultByOneJudgeResponse.Vote.isValid)
  
  return isvalid_.ReleaseNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited());
}
inline void GetVoteResultByOneJudgeResponse_Vote::set_allocated_isvalid(::std::string* isvalid) {
  if (isvalid != NULL) {
    
  } else {
    
  }
  isvalid_.SetAllocatedNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited(), isvalid);
  // @@protoc_insertion_point(field_set_allocated:protoMsg.GetVoteResultByOneJudgeResponse.Vote.isValid)
}

// string isVoted = 4;
inline void GetVoteResultByOneJudgeResponse_Vote::clear_isvoted() {
  isvoted_.ClearToEmptyNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited());
}
inline const ::std::string& GetVoteResultByOneJudgeResponse_Vote::isvoted() const {
  // @@protoc_insertion_point(field_get:protoMsg.GetVoteResultByOneJudgeResponse.Vote.isVoted)
  return isvoted_.GetNoArena();
}
inline void GetVoteResultByOneJudgeResponse_Vote::set_isvoted(const ::std::string& value) {
  
  isvoted_.SetNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited(), value);
  // @@protoc_insertion_point(field_set:protoMsg.GetVoteResultByOneJudgeResponse.Vote.isVoted)
}
#if LANG_CXX11
inline void GetVoteResultByOneJudgeResponse_Vote::set_isvoted(::std::string&& value) {
  
  isvoted_.SetNoArena(
    &::google::protobuf::internal::GetEmptyStringAlreadyInited(), ::std::move(value));
  // @@protoc_insertion_point(field_set_rvalue:protoMsg.GetVoteResultByOneJudgeResponse.Vote.isVoted)
}
#endif
inline void GetVoteResultByOneJudgeResponse_Vote::set_isvoted(const char* value) {
  GOOGLE_DCHECK(value != NULL);
  
  isvoted_.SetNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited(), ::std::string(value));
  // @@protoc_insertion_point(field_set_char:protoMsg.GetVoteResultByOneJudgeResponse.Vote.isVoted)
}
inline void GetVoteResultByOneJudgeResponse_Vote::set_isvoted(const char* value, size_t size) {
  
  isvoted_.SetNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited(),
      ::std::string(reinterpret_cast<const char*>(value), size));
  // @@protoc_insertion_point(field_set_pointer:protoMsg.GetVoteResultByOneJudgeResponse.Vote.isVoted)
}
inline ::std::string* GetVoteResultByOneJudgeResponse_Vote::mutable_isvoted() {
  
  // @@protoc_insertion_point(field_mutable:protoMsg.GetVoteResultByOneJudgeResponse.Vote.isVoted)
  return isvoted_.MutableNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited());
}
inline ::std::string* GetVoteResultByOneJudgeResponse_Vote::release_isvoted() {
  // @@protoc_insertion_point(field_release:protoMsg.GetVoteResultByOneJudgeResponse.Vote.isVoted)
  
  return isvoted_.ReleaseNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited());
}
inline void GetVoteResultByOneJudgeResponse_Vote::set_allocated_isvoted(::std::string* isvoted) {
  if (isvoted != NULL) {
    
  } else {
    
  }
  isvoted_.SetAllocatedNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited(), isvoted);
  // @@protoc_insertion_point(field_set_allocated:protoMsg.GetVoteResultByOneJudgeResponse.Vote.isVoted)
}

// -------------------------------------------------------------------

// GetVoteResultByOneJudgeResponse

// repeated .protoMsg.GetVoteResultByOneJudgeResponse.Vote votes = 1;
inline int GetVoteResultByOneJudgeResponse::votes_size() const {
  return votes_.size();
}
inline void GetVoteResultByOneJudgeResponse::clear_votes() {
  votes_.Clear();
}
inline ::protoMsg::GetVoteResultByOneJudgeResponse_Vote* GetVoteResultByOneJudgeResponse::mutable_votes(int index) {
  // @@protoc_insertion_point(field_mutable:protoMsg.GetVoteResultByOneJudgeResponse.votes)
  return votes_.Mutable(index);
}
inline ::google::protobuf::RepeatedPtrField< ::protoMsg::GetVoteResultByOneJudgeResponse_Vote >*
GetVoteResultByOneJudgeResponse::mutable_votes() {
  // @@protoc_insertion_point(field_mutable_list:protoMsg.GetVoteResultByOneJudgeResponse.votes)
  return &votes_;
}
inline const ::protoMsg::GetVoteResultByOneJudgeResponse_Vote& GetVoteResultByOneJudgeResponse::votes(int index) const {
  // @@protoc_insertion_point(field_get:protoMsg.GetVoteResultByOneJudgeResponse.votes)
  return votes_.Get(index);
}
inline ::protoMsg::GetVoteResultByOneJudgeResponse_Vote* GetVoteResultByOneJudgeResponse::add_votes() {
  // @@protoc_insertion_point(field_add:protoMsg.GetVoteResultByOneJudgeResponse.votes)
  return votes_.Add();
}
inline const ::google::protobuf::RepeatedPtrField< ::protoMsg::GetVoteResultByOneJudgeResponse_Vote >&
GetVoteResultByOneJudgeResponse::votes() const {
  // @@protoc_insertion_point(field_list:protoMsg.GetVoteResultByOneJudgeResponse.votes)
  return votes_;
}

#ifdef __GNUC__
  #pragma GCC diagnostic pop
#endif  // __GNUC__
// -------------------------------------------------------------------


// @@protoc_insertion_point(namespace_scope)

}  // namespace protoMsg

// @@protoc_insertion_point(global_scope)

#endif  // PROTOBUF_INCLUDED_getVoteResultByOneJudgeResponse_2eproto
