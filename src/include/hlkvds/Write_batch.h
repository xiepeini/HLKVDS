#ifndef _HLKVDS_WRITE_BATCH_H_
#define _HLKVDS_WRITE_BATCH_H_

#include <list>
#include <string>

namespace hlkvds {

class KVSlice;
class KVDS;
class MultiVolumeDS;

class WriteBatch {
public:
    WriteBatch();
    ~WriteBatch();

    void put(const char *key, uint32_t key_len, const char* data,
            uint16_t length);
    void del(const char *key, uint32_t key_len);
    void clear();

private:
    std::list<KVSlice *> batch_;
    friend class KVDS;
    friend class MultiVolumeDS;
};

} // namespace hlkvds

#endif //#define _HLKVDS_WRITE_BATCH_H_
