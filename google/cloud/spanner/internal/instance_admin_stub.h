// Copyright 2019 Google LLC
//
// Licensed under the Apache License, Version 2.0 (the "License");
// you may not use this file except in compliance with the License.
// You may obtain a copy of the License at
//
//     http://www.apache.org/licenses/LICENSE-2.0
//
// Unless required by applicable law or agreed to in writing, software
// distributed under the License is distributed on an "AS IS" BASIS,
// WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
// See the License for the specific language governing permissions and
// limitations under the License.

#ifndef GOOGLE_CLOUD_CPP_SPANNER_GOOGLE_CLOUD_SPANNER_INTERNAL_INSTANCE_ADMIN_STUB_H_
#define GOOGLE_CLOUD_CPP_SPANNER_GOOGLE_CLOUD_SPANNER_INTERNAL_INSTANCE_ADMIN_STUB_H_

#include "google/cloud/spanner/connection_options.h"
#include "google/cloud/future.h"
#include "google/cloud/status_or.h"
#include <google/spanner/admin/instance/v1/spanner_instance_admin.grpc.pb.h>

namespace google {
namespace cloud {
namespace spanner {
inline namespace SPANNER_CLIENT_NS {
namespace internal {

namespace gcsa = google::spanner::admin::instance::v1;

/**
 * Defines the low-level interface for instance administration RPCs.
 */
class InstanceAdminStub {
 public:
  virtual ~InstanceAdminStub() = 0;

  virtual StatusOr<gcsa::Instance> GetInstance(
      grpc::ClientContext&, gcsa::GetInstanceRequest const&) = 0;

  virtual StatusOr<google::longrunning::Operation> CreateInstance(
      grpc::ClientContext&, gcsa::CreateInstanceRequest const&) = 0;

  virtual StatusOr<google::longrunning::Operation> UpdateInstance(
      grpc::ClientContext&, gcsa::UpdateInstanceRequest const&) = 0;

  virtual Status DeleteInstance(grpc::ClientContext&,
                                gcsa::DeleteInstanceRequest const&) = 0;

  virtual StatusOr<gcsa::InstanceConfig> GetInstanceConfig(
      grpc::ClientContext&, gcsa::GetInstanceConfigRequest const&) = 0;

  virtual StatusOr<gcsa::ListInstanceConfigsResponse> ListInstanceConfigs(
      grpc::ClientContext&, gcsa::ListInstanceConfigsRequest const&) = 0;

  virtual StatusOr<gcsa::ListInstancesResponse> ListInstances(
      grpc::ClientContext&, gcsa::ListInstancesRequest const&) = 0;

  virtual StatusOr<google::iam::v1::Policy> GetIamPolicy(
      grpc::ClientContext&, google::iam::v1::GetIamPolicyRequest const&) = 0;

  virtual StatusOr<google::iam::v1::Policy> SetIamPolicy(
      grpc::ClientContext&, google::iam::v1::SetIamPolicyRequest const&) = 0;

  virtual StatusOr<google::iam::v1::TestIamPermissionsResponse>
  TestIamPermissions(grpc::ClientContext&,
                     google::iam::v1::TestIamPermissionsRequest const&) = 0;
};

/**
 * Constructs a simple `DatabaseAdminStub`,
 *
 * This stub does not create a channel pool, or retry operations.
 */
std::shared_ptr<InstanceAdminStub> CreateDefaultInstanceAdminStub(
    ConnectionOptions const& options);

}  // namespace internal
}  // namespace SPANNER_CLIENT_NS
}  // namespace spanner
}  // namespace cloud
}  // namespace google

#endif  // GOOGLE_CLOUD_CPP_SPANNER_GOOGLE_CLOUD_SPANNER_INTERNAL_INSTANCE_ADMIN_STUB_H_
