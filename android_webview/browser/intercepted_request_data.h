// Copyright (c) 2012 The Chromium Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

#ifndef ANDROID_WEBVIEW_BROWSER_INTERCEPTED_REQUEST_DATA_H_
#define ANDROID_WEBVIEW_BROWSER_INTERCEPTED_REQUEST_DATA_H_

#include <string>

#include "base/memory/scoped_ptr.h"

namespace net {
class URLRequest;
class URLRequestJob;
class NetworkDelegate;
}

namespace android_webview {

// This class represents the Java-side data that is to be used to complete a
// particular URLRequest.
class InterceptedRequestData {
 public:
  virtual ~InterceptedRequestData() {}

  // This creates a URLRequestJob for the |request| wich will read data from
  // the |intercepted_request_data| structure (instead of going to the network
  // or to the cache).
  // The newly created job takes ownership of |intercepted_request_data|.
  static net::URLRequestJob* CreateJobFor(
      scoped_ptr<InterceptedRequestData> intercepted_request_data,
      net::URLRequest* request,
      net::NetworkDelegate* network_delegate);

 protected:
  InterceptedRequestData() {}

 private:
  DISALLOW_COPY_AND_ASSIGN(InterceptedRequestData);
};

} // namespace android_webview

#endif  // ANDROID_WEBVIEW_BROWSER_INTERCEPTED_REQUEST_DATA_H_
