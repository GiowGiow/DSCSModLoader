#include "ScriptExtension.h"

#include "dscs/GameInterface.h"
#include "modloader/plugin.h"

namespace dscs
{
    namespace digimon
    {
        int64_t GetScan(int64_t)
        {
            return 0;
        }

        void AddScan(int64_t, int64_t)
        {
        }

        void SetScan(int64_t, int64_t)
        {
        }
    } // namespace digimon
    namespace modloader
    {
        void SetFlag(const SQChar* name, int32_t flag)
        {
            std::string string{ name };
            DSCSModLoader::getInstance().getFlagTable(string).set(flag);
        }
        bool GetFlag(const SQChar* name, int32_t flag)
        {
            std::string string{ name };
            return DSCSModLoader::getInstance().getFlagTable(string).get(flag);
        }
        void ClearFlag(const SQChar* name, int32_t flag)
        {
            std::string string{ name };
            DSCSModLoader::getInstance().getFlagTable(string).clear(flag);
        }

        void StorageSetInt(const SQChar* name, int32_t flag, int32_t value)
        {
            std::string string{ name };
            DSCSModLoader::getInstance().getWorkTable(string).setInt(flag, value);
        }
        void StorageSetFloat(const SQChar* name, int32_t flag, float value)
        {
            std::string string{ name };
            DSCSModLoader::getInstance().getWorkTable(string).setFloat(flag, value);
        }
        int32_t StorageGetInt(const SQChar* name, int32_t flag)
        {
            std::string string{ name };
            return DSCSModLoader::getInstance().getWorkTable(string).getInt(flag);
        }
        float StorageGetFloat(const SQChar* name, int32_t flag)
        {
            std::string string{ name };
            return DSCSModLoader::getInstance().getWorkTable(string).getFloat(flag);
        }

        void DebugLog(HSQUIRRELVM vm, const SQChar* msg) { sq_getprintfunc(vm)(vm, msg); }

    } // namespace modloader
} // namespace dscs
