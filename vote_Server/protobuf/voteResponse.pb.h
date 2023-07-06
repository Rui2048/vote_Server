// Generated by the protocol buffer compiler.  DO NOT EDIT!
// source: voteResponse.proto

#ifndef PROTOBUF_INCLUDED_voteResponse_2eproto
#define PROTOBUF_INCLUDED_voteResponse_2eproto

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
#define PROTOBUF_INTERNAL_EXPORT_protobuf_voteResponse_2eproto 

namespace protobuf_voteResponse_2eproto {
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
}  // namespace protobuf_voteResponse_2eproto
namespace protoMsg {
class VoteResponse;
class VoteResponseDefaultTypeInternal;
extern VoteResponseDefaultTypeInternal _VoteResponse_default_instance_;
class VoteResponse_Plaerscore;
class VoteResponse_PlaerscoreDefaultTypeInternal;
extern VoteResponse_PlaerscoreDefaultTypeInternal _VoteResponse_Plaerscore_default_instance_;
}  // namespace protoMsg
namespace google {
namespace protobuf {
template<> ::protoMsg::VoteResponse* Arena::CreateMaybeMessage<::protoMsg::VoteResponse>(Arena*);
template<> ::protoMsg::VoteResponse_Plaerscore* Arena::CreateMaybeMessage<::protoMsg::VoteResponse_Plaerscore>(Arena*);
}  // namespace protobuf
}  // namespace google
namespace protoMsg {

// ===================================================================

class VoteResponse_Plaerscore : public ::google::protobuf::Message /* @@protoc_insertion_point(class_definition:protoMsg.VoteResponse.Plaerscore) */ {
 public:
  VoteResponse_Plaerscore();
  virtual ~VoteResponse_Plaerscore();

  VoteResponse_Plaerscore(const VoteResponse_Plaerscore& from);

  inline VoteResponse_Plaerscore& operator=(const VoteResponse_Plaerscore& from) {
    CopyFrom(from);
    return *this;
  }
  #if LANG_CXX11
  VoteResponse_Plaerscore(VoteResponse_Plaerscore&& from) noexcept
    : VoteResponse_Plaerscore() {
    *this = ::std::move(from);
  }

  inline VoteResponse_Plaerscore& operator=(VoteResponse_Plaerscore&& from) noexcept {
    if (GetArenaNoVirtual() == from.GetArenaNoVirtual()) {
      if (this != &from) InternalSwap(&from);
    } else {
      CopyFrom(from);
    }
    return *this;
  }
  #endif
  static const ::google::protobuf::Descriptor* descriptor();
  static const VoteResponse_Plaerscore& default_instance();

  static void InitAsDefaultInstance();  // FOR INTERNAL USE ONLY
  static inline const VoteResponse_Plaerscore* internal_default_instance() {
    return reinterpret_cast<const VoteResponse_Plaerscore*>(
               &_VoteResponse_Plaerscore_default_instance_);
  }
  static constexpr int kIndexInFileMessages =
    0;

  void Swap(VoteResponse_Plaerscore* other);
  friend void swap(VoteResponse_Plaerscore& a, VoteResponse_Plaerscore& b) {
    a.Swap(&b);
  }

  // implements Message ----------------------------------------------

  inline VoteResponse_Plaerscore* New() const final {
    return CreateMaybeMessage<VoteResponse_Plaerscore>(NULL);
  }

  VoteResponse_Plaerscore* New(::google::protobuf::Arena* arena) const final {
    return CreateMaybeMessage<VoteResponse_Plaerscore>(arena);
  }
  void CopyFrom(const ::google::protobuf::Message& from) final;
  void MergeFrom(const ::google::protobuf::Message& from) final;
  void CopyFrom(const VoteResponse_Plaerscore& from);
  void MergeFrom(const VoteResponse_Plaerscore& from);
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
  void InternalSwap(VoteResponse_Plaerscore* other);
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

  // string name = 1;
  void clear_name();
  static const int kNameFieldNumber = 1;
  const ::std::string& name() const;
  void set_name(const ::std::string& value);
  #if LANG_CXX11
  void set_name(::std::string&& value);
  #endif
  void set_name(const char* value);
  void set_name(const char* value, size_t size);
  ::std::string* mutable_name();
  ::std::string* release_name();
  void set_allocated_name(::std::string* name);

  // string score = 2;
  void clear_score();
  static const int kScoreFieldNumber = 2;
  const ::std::string& score() const;
  void set_score(const ::std::string& value);
  #if LANG_CXX11
  void set_score(::std::string&& value);
  #endif
  void set_score(const char* value);
  void set_score(const char* value, size_t size);
  ::std::string* mutable_score();
  ::std::string* release_score();
  void set_allocated_score(::std::string* score);

  // @@protoc_insertion_point(class_scope:protoMsg.VoteResponse.Plaerscore)
 private:

  ::google::protobuf::internal::InternalMetadataWithArena _internal_metadata_;
  ::google::protobuf::internal::ArenaStringPtr name_;
  ::google::protobuf::internal::ArenaStringPtr score_;
  mutable ::google::protobuf::internal::CachedSize _cached_size_;
  friend struct ::protobuf_voteResponse_2eproto::TableStruct;
};
// -------------------------------------------------------------------

class VoteResponse : public ::google::protobuf::Message /* @@protoc_insertion_point(class_definition:protoMsg.VoteResponse) */ {
 public:
  VoteResponse();
  virtual ~VoteResponse();

  VoteResponse(const VoteResponse& from);

  inline VoteResponse& operator=(const VoteResponse& from) {
    CopyFrom(from);
    return *this;
  }
  #if LANG_CXX11
  VoteResponse(VoteResponse&& from) noexcept
    : VoteResponse() {
    *this = ::std::move(from);
  }

  inline VoteResponse& operator=(VoteResponse&& from) noexcept {
    if (GetArenaNoVirtual() == from.GetArenaNoVirtual()) {
      if (this != &from) InternalSwap(&from);
    } else {
      CopyFrom(from);
    }
    return *this;
  }
  #endif
  static const ::google::protobuf::Descriptor* descriptor();
  static const VoteResponse& default_instance();

  static void InitAsDefaultInstance();  // FOR INTERNAL USE ONLY
  static inline const VoteResponse* internal_default_instance() {
    return reinterpret_cast<const VoteResponse*>(
               &_VoteResponse_default_instance_);
  }
  static constexpr int kIndexInFileMessages =
    1;

  void Swap(VoteResponse* other);
  friend void swap(VoteResponse& a, VoteResponse& b) {
    a.Swap(&b);
  }

  // implements Message ----------------------------------------------

  inline VoteResponse* New() const final {
    return CreateMaybeMessage<VoteResponse>(NULL);
  }

  VoteResponse* New(::google::protobuf::Arena* arena) const final {
    return CreateMaybeMessage<VoteResponse>(arena);
  }
  void CopyFrom(const ::google::protobuf::Message& from) final;
  void MergeFrom(const ::google::protobuf::Message& from) final;
  void CopyFrom(const VoteResponse& from);
  void MergeFrom(const VoteResponse& from);
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
  void InternalSwap(VoteResponse* other);
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

  typedef VoteResponse_Plaerscore Plaerscore;

  // accessors -------------------------------------------------------

  // repeated .protoMsg.VoteResponse.Plaerscore playerScores = 1;
  int playerscores_size() const;
  void clear_playerscores();
  static const int kPlayerScoresFieldNumber = 1;
  ::protoMsg::VoteResponse_Plaerscore* mutable_playerscores(int index);
  ::google::protobuf::RepeatedPtrField< ::protoMsg::VoteResponse_Plaerscore >*
      mutable_playerscores();
  const ::protoMsg::VoteResponse_Plaerscore& playerscores(int index) const;
  ::protoMsg::VoteResponse_Plaerscore* add_playerscores();
  const ::google::protobuf::RepeatedPtrField< ::protoMsg::VoteResponse_Plaerscore >&
      playerscores() const;

  // @@protoc_insertion_point(class_scope:protoMsg.VoteResponse)
 private:

  ::google::protobuf::internal::InternalMetadataWithArena _internal_metadata_;
  ::google::protobuf::RepeatedPtrField< ::protoMsg::VoteResponse_Plaerscore > playerscores_;
  mutable ::google::protobuf::internal::CachedSize _cached_size_;
  friend struct ::protobuf_voteResponse_2eproto::TableStruct;
};
// ===================================================================


// ===================================================================

#ifdef __GNUC__
  #pragma GCC diagnostic push
  #pragma GCC diagnostic ignored "-Wstrict-aliasing"
#endif  // __GNUC__
// VoteResponse_Plaerscore

// string name = 1;
inline void VoteResponse_Plaerscore::clear_name() {
  name_.ClearToEmptyNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited());
}
inline const ::std::string& VoteResponse_Plaerscore::name() const {
  // @@protoc_insertion_point(field_get:protoMsg.VoteResponse.Plaerscore.name)
  return name_.GetNoArena();
}
inline void VoteResponse_Plaerscore::set_name(const ::std::string& value) {
  
  name_.SetNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited(), value);
  // @@protoc_insertion_point(field_set:protoMsg.VoteResponse.Plaerscore.name)
}
#if LANG_CXX11
inline void VoteResponse_Plaerscore::set_name(::std::string&& value) {
  
  name_.SetNoArena(
    &::google::protobuf::internal::GetEmptyStringAlreadyInited(), ::std::move(value));
  // @@protoc_insertion_point(field_set_rvalue:protoMsg.VoteResponse.Plaerscore.name)
}
#endif
inline void VoteResponse_Plaerscore::set_name(const char* value) {
  GOOGLE_DCHECK(value != NULL);
  
  name_.SetNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited(), ::std::string(value));
  // @@protoc_insertion_point(field_set_char:protoMsg.VoteResponse.Plaerscore.name)
}
inline void VoteResponse_Plaerscore::set_name(const char* value, size_t size) {
  
  name_.SetNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited(),
      ::std::string(reinterpret_cast<const char*>(value), size));
  // @@protoc_insertion_point(field_set_pointer:protoMsg.VoteResponse.Plaerscore.name)
}
inline ::std::string* VoteResponse_Plaerscore::mutable_name() {
  
  // @@protoc_insertion_point(field_mutable:protoMsg.VoteResponse.Plaerscore.name)
  return name_.MutableNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited());
}
inline ::std::string* VoteResponse_Plaerscore::release_name() {
  // @@protoc_insertion_point(field_release:protoMsg.VoteResponse.Plaerscore.name)
  
  return name_.ReleaseNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited());
}
inline void VoteResponse_Plaerscore::set_allocated_name(::std::string* name) {
  if (name != NULL) {
    
  } else {
    
  }
  name_.SetAllocatedNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited(), name);
  // @@protoc_insertion_point(field_set_allocated:protoMsg.VoteResponse.Plaerscore.name)
}

// string score = 2;
inline void VoteResponse_Plaerscore::clear_score() {
  score_.ClearToEmptyNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited());
}
inline const ::std::string& VoteResponse_Plaerscore::score() const {
  // @@protoc_insertion_point(field_get:protoMsg.VoteResponse.Plaerscore.score)
  return score_.GetNoArena();
}
inline void VoteResponse_Plaerscore::set_score(const ::std::string& value) {
  
  score_.SetNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited(), value);
  // @@protoc_insertion_point(field_set:protoMsg.VoteResponse.Plaerscore.score)
}
#if LANG_CXX11
inline void VoteResponse_Plaerscore::set_score(::std::string&& value) {
  
  score_.SetNoArena(
    &::google::protobuf::internal::GetEmptyStringAlreadyInited(), ::std::move(value));
  // @@protoc_insertion_point(field_set_rvalue:protoMsg.VoteResponse.Plaerscore.score)
}
#endif
inline void VoteResponse_Plaerscore::set_score(const char* value) {
  GOOGLE_DCHECK(value != NULL);
  
  score_.SetNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited(), ::std::string(value));
  // @@protoc_insertion_point(field_set_char:protoMsg.VoteResponse.Plaerscore.score)
}
inline void VoteResponse_Plaerscore::set_score(const char* value, size_t size) {
  
  score_.SetNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited(),
      ::std::string(reinterpret_cast<const char*>(value), size));
  // @@protoc_insertion_point(field_set_pointer:protoMsg.VoteResponse.Plaerscore.score)
}
inline ::std::string* VoteResponse_Plaerscore::mutable_score() {
  
  // @@protoc_insertion_point(field_mutable:protoMsg.VoteResponse.Plaerscore.score)
  return score_.MutableNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited());
}
inline ::std::string* VoteResponse_Plaerscore::release_score() {
  // @@protoc_insertion_point(field_release:protoMsg.VoteResponse.Plaerscore.score)
  
  return score_.ReleaseNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited());
}
inline void VoteResponse_Plaerscore::set_allocated_score(::std::string* score) {
  if (score != NULL) {
    
  } else {
    
  }
  score_.SetAllocatedNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited(), score);
  // @@protoc_insertion_point(field_set_allocated:protoMsg.VoteResponse.Plaerscore.score)
}

// -------------------------------------------------------------------

// VoteResponse

// repeated .protoMsg.VoteResponse.Plaerscore playerScores = 1;
inline int VoteResponse::playerscores_size() const {
  return playerscores_.size();
}
inline void VoteResponse::clear_playerscores() {
  playerscores_.Clear();
}
inline ::protoMsg::VoteResponse_Plaerscore* VoteResponse::mutable_playerscores(int index) {
  // @@protoc_insertion_point(field_mutable:protoMsg.VoteResponse.playerScores)
  return playerscores_.Mutable(index);
}
inline ::google::protobuf::RepeatedPtrField< ::protoMsg::VoteResponse_Plaerscore >*
VoteResponse::mutable_playerscores() {
  // @@protoc_insertion_point(field_mutable_list:protoMsg.VoteResponse.playerScores)
  return &playerscores_;
}
inline const ::protoMsg::VoteResponse_Plaerscore& VoteResponse::playerscores(int index) const {
  // @@protoc_insertion_point(field_get:protoMsg.VoteResponse.playerScores)
  return playerscores_.Get(index);
}
inline ::protoMsg::VoteResponse_Plaerscore* VoteResponse::add_playerscores() {
  // @@protoc_insertion_point(field_add:protoMsg.VoteResponse.playerScores)
  return playerscores_.Add();
}
inline const ::google::protobuf::RepeatedPtrField< ::protoMsg::VoteResponse_Plaerscore >&
VoteResponse::playerscores() const {
  // @@protoc_insertion_point(field_list:protoMsg.VoteResponse.playerScores)
  return playerscores_;
}

#ifdef __GNUC__
  #pragma GCC diagnostic pop
#endif  // __GNUC__
// -------------------------------------------------------------------


// @@protoc_insertion_point(namespace_scope)

}  // namespace protoMsg

// @@protoc_insertion_point(global_scope)

#endif  // PROTOBUF_INCLUDED_voteResponse_2eproto
