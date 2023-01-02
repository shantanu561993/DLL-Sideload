// to make sure the dll is loaded before the function intercept is introduced
const dllName = "C:\\WINDOWS\\SYSTEM32\\FxsCompose.dll";
Module.load(dllName);

//find the address of the function
var pHrInitComposeFormDll = Module.findExportByName("FxsCompose.dll","HrInitComposeFormDll");


//intercept the call
Interceptor.attach(pHrInitComposeFormDll, {
    onEnter: function (args) {
        send("The function was called")
    },
    onLeave: function (retval) {
    }
});